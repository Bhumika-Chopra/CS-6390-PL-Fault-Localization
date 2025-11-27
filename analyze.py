#!/usr/bin/env python3

import json
import subprocess
import tempfile
import sys
import os

def run_cmd(cmd, input=None):
    p = subprocess.Popen(
        cmd,
        stdin=subprocess.PIPE if input else None,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    out, err = p.communicate(input)
    return p.returncode, out, err


def analyze_file(source_file, clang_args):
    # 1. Run extractor
    cwd = os.path.dirname(__file__)
    path = os.path.join(cwd, "CodeSlicing/extract_blocks.py")
    extractor_cmd = ["python3", path, source_file]
    
    if clang_args:
        extractor_cmd += ["--"] + clang_args

    ret, out, err = run_cmd(extractor_cmd)

    if ret != 0:
        print("Extractor failed:", err)
        sys.exit(1)

    units = json.loads(out)

    results = []

    # 2. Analyze each unit
    for u in units:
        code = u["wrapper_source"]
        with tempfile.NamedTemporaryFile(suffix=".cpp", delete=False) as tmp:
            tmp.write(code.encode("utf-8"))
            tmp_path = tmp.name

        # run compiler_warnings.py
        path = os.path.join(cwd, "CompilerWarnings/compiler_warnings.py")
        ret, out, err = run_cmd(["python3", path, tmp_path])

        try:
            diagnostics = json.loads(out)
        except json.JSONDecodeError:
            diagnostics = {"error": "failed to parse compiler output", "raw": out}

        results.append({
            "id": u["id"],
            "name": u["name"],
            "kind": u["kind"],
            "start_line": u["start_line"],
            "end_line": u["end_line"],
            "compiler_diagnostics": diagnostics,
        })

        os.remove(tmp_path)

    return results


def main():
    if len(sys.argv) < 2:
        print("Usage: python analyze.py file.cpp -- [clang args]")
        sys.exit(1)

    if "--" in sys.argv:
        idx = sys.argv.index("--")
        source_file = sys.argv[1]
        clang_args = sys.argv[idx+1:]
    else:
        source_file = sys.argv[1]
        clang_args = []

    results = analyze_file(source_file, clang_args)
    print(json.dumps(results, indent=2))


if __name__ == "__main__":
    main()
