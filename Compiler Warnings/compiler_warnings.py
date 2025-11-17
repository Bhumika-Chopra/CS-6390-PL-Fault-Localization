import subprocess
import tempfile
import os
import json
import shutil
import sys

def get_compiler():
    """Return clang++ if available, otherwise g++."""
    if shutil.which("clang++"):
        return "clang++"
    elif shutil.which("g++"):
        return "g++"
    else:
        raise RuntimeError("Neither clang++ nor g++ is installed.")


def compile_and_collect_warnings(code_path):
    compiler = get_compiler()

    # Flags optimized for *max diagnostic information*
    if "clang++" in compiler:
        flags = [
            "-Weverything",
            "-Wno-c++98-compat",
            "-Wno-c++98-compat-pedantic",
            "-fsyntax-only",
            "-fsave-optimization-record",
            "-Rpass=.*",
            "-Rpass-analysis=.*",
            "-Rpass-missed=.*"
        ]
    else:  # GCC
        flags = [
            "-Wall", "-Wextra", "-Wpedantic",
            "-fanalyzer",
            "-fopt-info",
            "-fsyntax-only"
        ]

    safe_flags = [flag.replace(".*", ".\\*") for flag in flags]

    process = subprocess.Popen(
        [compiler] + safe_flags + [code_path],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        universal_newlines=True
    )

    stdout, stderr = process.communicate()

    # Return warnings as structured data
    return {
        "compiler": compiler,
        "return_code": process.returncode,
        "stdout": stdout.strip(),
        "stderr": stderr.strip(),
        "warnings": parse_warnings(stderr),
    }


def parse_warnings(compiler_output):
    """
    Extracts lines that contain warnings, errors, or optimization remarks.
    You can later categorize these by:
      - C++ Standard category (lexical, syntax, ODR, etc.)
      - Clang warning groups
      - GCC diagnostic categories
    """

    lines = compiler_output.split("\n")
    warnings = []

    for line in lines:
        if not line.strip():
            continue

        lower = line.lower()

        if ("warning:" in lower or
            "error:" in lower or
            "remark:" in lower or
            "note:" in lower):

            warnings.append(line.strip())

    return warnings


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python extract_warnings.py <file.cpp>")
        sys.exit(1)

    code_path = sys.argv[1]

    if not os.path.isfile(code_path):
        print(f"Error: file not found: {code_path}")
        sys.exit(1)

    results = compile_and_collect_warnings(code_path)

    print(json.dumps(results, indent=2))
