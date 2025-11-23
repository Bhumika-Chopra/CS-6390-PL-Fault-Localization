import subprocess
import os
import json
import shutil
import sys

# ---------------------------
# Load Severity Rules from JSON
# ---------------------------
RULES_FILE = "./severity_rules.json"

if not os.path.isfile(RULES_FILE):
    raise FileNotFoundError(f"Severity rules file not found: {RULES_FILE}")

with open(RULES_FILE, "r") as f:
    SEVERITY_RULES = json.load(f)
# Ensure keys are integers
SEVERITY_RULES = {int(k): v for k, v in SEVERITY_RULES.items()}


# ---------------------------
# Compiler Selection
# ---------------------------
def get_compiler():
    if shutil.which("clang++"):
        return "clang++"
    elif shutil.which("g++"):
        return "g++"
    else:
        raise RuntimeError("Neither clang++ nor g++ is installed.")


# ---------------------------
# Categorize Warnings
# ---------------------------
def categorize_by_severity(warnings):
    groups = {1: [], 2: [], 3: [], 4: []}

    for w in warnings:
        lw = w.lower()
        assigned = False
        for level, keywords in SEVERITY_RULES.items():
            if any(k in lw for k in keywords):
                groups[level].append(w)
                assigned = True
                break
        if not assigned:
            groups[4].append(w)

    return groups


def compute_badness_score(groups):
    weights = {1: 1.0, 2: 0.7, 3: 0.4, 4: 0.1}
    weighted_sum = sum(weights[level] * len(groups[level]) for level in groups)
    count = sum(len(groups[level]) for level in groups)
    return weighted_sum / count if count > 0 else 0.0


# ---------------------------
# Compile & Collect Warnings
# ---------------------------
def compile_and_collect_warnings(code_path):
    compiler = get_compiler()

    if "clang++" in compiler:
        flags = [
            # Collect all warnings
            "-Weverything",
            # Suppress warnings that are not relevant for modern C++
            "-Wno-c++98-compat",
            # Only do static analysis, no code generation
            "-fsyntax-only",
            # O1 is good enough to trigger optimizations without excessive compile time
            # Anyhow are programs aren't very complex
            "-O1",
            # Let's us know what optimizations were applied
            # and which were missed
            "-Rpass=all",
            "-Rpass-analysis=all",
            "-Rpass-missed=all"
        ]
    else:  # GCC
        flags = [
            "-Wall",
            "-Wextra",
            "-Wpedantic",
            "-fanalyzer",
            "-fopt-info-all",
            "-fsyntax-only",
            "-O1"
        ]

    safe_flags = [flag.replace(".*", ".\\*") for flag in flags]

    process = subprocess.Popen(
        [compiler] + safe_flags + [code_path],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        universal_newlines=True
    )

    stdout, stderr = process.communicate()

    warnings = parse_warnings(stderr)
    groups = categorize_by_severity(warnings)
    score = compute_badness_score(groups)

    return {
        "compiler": compiler,
        "return_code": process.returncode,
        "stdout": stdout.strip(),
        "stderr": stderr.strip(),
        # "warnings": warnings,
        "severity_groups": groups,
        "diagnostic_flags": flags,
        "badness_score": score
    }


# ---------------------------
# Extract Warning Lines
# ---------------------------
def parse_warnings(compiler_output):
    lines = compiler_output.split("\n")
    warnings = []
    for line in lines:
        if not line.strip():
            continue
        lower = line.lower()
        if "warning:" in lower or "error:" in lower or "remark:" in lower or "note:" in lower:
            warnings.append(line.strip())
    return warnings


# ---------------------------
# Main Program Entry Point
# ---------------------------
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python extract_warnings.py <file.cpp>")
        sys.exit(1)

    code_path = sys.argv[1]
    if not os.path.isfile(code_path):
        print(f"Error: could not find program file: {code_path}")
        sys.exit(1)

    results = compile_and_collect_warnings(code_path)
    print(json.dumps(results, indent=2))
