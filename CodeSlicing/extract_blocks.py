#!/usr/bin/env python3
"""
extract_functions.py

Usage:
  python extract_functions.py source.cpp -- -I/path/to/includes -DFOO

This outputs a JSON array with extracted units to stdout.
Each unit has:
  - id
  - kind (function/method/ctor/dtor/template)
  - name
  - start_line, end_line
  - wrapper_source  (complete compilable unit you can pass to your compiler script)
  - raw_source      (the extracted snippet from original file)
"""

import sys
import json
import os
from clang import cindex

cindex.Config.set_library_file("/opt/homebrew/opt/llvm@21/lib/libclang.dylib")

def load_file_text(path):
    with open(path, "r", encoding="utf-8", errors="replace") as f:
        return f.read()

def linecol_to_offset(source_text, line, col):
    # line, col are 1-based
    lines = source_text.splitlines(keepends=True)
    if line - 1 >= len(lines):
        return len(source_text)
    # sum lengths of prior lines
    offset = sum(len(lines[i]) for i in range(line - 1))
    # column is 1-based; convert to 0-based char index in that line
    offset += max(0, col - 1)
    return offset

# Node kinds we treat as function-like
FUNCTION_KINDS = {
    cindex.CursorKind.FUNCTION_DECL,
    cindex.CursorKind.CXX_METHOD,
    cindex.CursorKind.CONSTRUCTOR,
    cindex.CursorKind.DESTRUCTOR,
    cindex.CursorKind.FUNCTION_TEMPLATE,
}

# Parent kinds to include if method needs class definition
PARENT_CLASS_KINDS = {
    cindex.CursorKind.CLASS_DECL,
    cindex.CursorKind.STRUCT_DECL,
    cindex.CursorKind.CLASS_TEMPLATE,
}

def get_source_snippet(source_text, start, end):
    # start and end are (line, column) pairs (1-based)
    s_off = linecol_to_offset(source_text, start[0], start[1])
    e_off = linecol_to_offset(source_text, end[0], end[1])
    return source_text[s_off:e_off]

def make_wrapper(preamble, snippet, add_main=True):
    """
    Create a compilable wrapper for a snippet.
    We put the snippet in global scope if it's a function,
    otherwise wrap as a function body of a synthetic function.
    """
    wrapper = []
    # basic preamble
    wrapper.append("#include <iostream>")
    wrapper.append("using namespace std;")
    if preamble:
        wrapper.append(preamble)
    wrapper.append("\n// --- extracted snippet begin ---\n")
    wrapper.append(snippet)
    wrapper.append("\n// --- extracted snippet end ---\n")
    # add a trivial main so it compiles
    if add_main:
        wrapper.append("int main(){ return 0; }")
    return "\n".join(wrapper)

def extract_units(filename, clang_args):
    index = cindex.Index.create()
    # parse
    tu = index.parse(filename, args=clang_args)
    src_text = load_file_text(filename)

    units = []
    uid = 0

    def visit(node, parent=None):
        nonlocal uid
        try:
            kind = node.kind
        except Exception:
            return  # defensive

        # handle function-like nodes
        if kind in FUNCTION_KINDS and node.is_definition():
            # get extent
            start = (node.extent.start.line, node.extent.start.column)
            end   = (node.extent.end.line,   node.extent.end.column)
            raw = get_source_snippet(src_text, start, end)

            # determine preamble: if method, try to include parent class declaration source
            preamble = ""
            parent = node.semantic_parent
            if parent and parent.kind in PARENT_CLASS_KINDS:
                # include parent extent (class/struct) to help compilation
                pstart = (parent.extent.start.line, parent.extent.start.column)
                pend   = (parent.extent.end.line,   parent.extent.end.column)
                # if parent encloses the method, raw will already have class; only prepend if separate
                parent_text = get_source_snippet(src_text, pstart, pend)
                # if parent_text contains the method body, we may duplicate; keep a safe approach:
                # If parent_text length < raw (unlikely) or parent_text == raw -> skip
                if parent_text.strip() and parent_text not in raw:
                    preamble = parent_text

            name = node.spelling or "<anon>"
            qname = node.get_usr() or name

            wrapper = make_wrapper(preamble, raw, name not in ["main", "Main"])

            units.append({
                "id": uid,
                "kind": str(kind).split(".")[-1],
                "name": name,
                "usr": qname,
                "start_line": start[0],
                "end_line": end[0],
                "raw_source": raw,
                "wrapper_source": wrapper
            })
            uid += 1
        
        # recurse children
        for c in node.get_children():
            visit(c, node)

    visit(tu.cursor)
    return units


def main():
    if len(sys.argv) < 2:
        print("Usage: python extract_blocks.py file.cpp -- [clang args]")
        sys.exit(1)
    # split CLI args: everything after -- is passed to libclang
    if "--" in sys.argv:
        idx = sys.argv.index("--")
        source_file = sys.argv[1]
        clang_args = sys.argv[idx+1:]
    else:
        source_file = sys.argv[1]
        clang_args = []

    units = extract_units(source_file, clang_args)
    print(json.dumps(units, indent=2))

if __name__ == "__main__":
    main()
