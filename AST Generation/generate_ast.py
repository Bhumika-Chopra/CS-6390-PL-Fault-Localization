import clang.cindex
import os
import json


def try_load_clang():
    possible_paths = [
        "/opt/homebrew/opt/llvm/lib/libclang.dylib",  
        "/usr/local/opt/llvm/lib/libclang.dylib",    
        "/Library/Developer/CommandLineTools/usr/lib/libclang.dylib", 
    ]

    for p in possible_paths:
        if os.path.exists(p):
            clang.cindex.Config.set_library_file(p)
            print(f"[INFO] Using libclang at: {p}")
            return

try_load_clang()


# ---------------------------------------------------------------------
# Convert AST nodes to Python dict
# ---------------------------------------------------------------------

def node_to_dict(node):
    children = [node_to_dict(c) for c in node.get_children()]

    return {
        "kind": str(node.kind).replace("CursorKind.", ""),
        "spelling": node.spelling,
        "type": node.type.spelling if node.type.kind != clang.cindex.TypeKind.INVALID else "",
        "location": {
            "file": str(node.location.file) if node.location.file else None,
            "line": node.location.line,
            "col": node.location.column
        },
        "children": children
    }


# ---------------------------------------------------------------------
# Parse file → return AST dict
# ---------------------------------------------------------------------

def generate_ast(filename, compiler_args=None):
    if compiler_args is None:
        compiler_args = ["-std=c++17"]

    index = clang.cindex.Index.create()
    tu = index.parse(filename, args=compiler_args)

    for d in tu.diagnostics:
        print("DIAG:", d)

    return node_to_dict(tu.cursor)


# ---------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------

if __name__ == "__main__":
    import sys

    if len(sys.argv) < 2:
        print("Usage: python generate_ast.py <cpp_file>")
        exit(1)

    ast = generate_ast(sys.argv[1])
    print(json.dumps(ast, indent=2))
