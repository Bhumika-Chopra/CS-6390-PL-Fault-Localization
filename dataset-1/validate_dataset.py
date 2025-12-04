import os
import sys
import json
from pathlib import Path

if sys.platform == 'win32':
    import codecs
    sys.stdout = codecs.getwriter('utf-8')(sys.stdout.buffer, 'strict')
    sys.stderr = codecs.getwriter('utf-8')(sys.stderr.buffer, 'strict')

sys.path.insert(0, os.path.dirname(__file__))
from extract_warnings import compile_and_collect_warnings


def validate_dataset():
    base_dir = Path(os.path.dirname(__file__))
    normal_dir = base_dir / "normal"
    spaghetti_dir = base_dir / "spaghetti"
    
    if not normal_dir.exists() or not spaghetti_dir.exists():
        print("Error: normal/ and spaghetti/ directories not found")
        return False
    
    results = {
        "total_samples": 0,
        "passed": 0,
        "caution": 0,
        "failed": 0,
        "caution_samples": [],
        "failures": [],
        "sample_scores": []
    }
    
    print("=" * 70)
    print("DATASET VALIDATION - Spaghetti Badness Score > Normal")
    print("=" * 70)
    print()
    
    for i in range(1, 161):
        sample_name = f"sample_{i:02d}.cpp"
        normal_file = normal_dir / sample_name
        spaghetti_file = spaghetti_dir / sample_name
        
        if not normal_file.exists() or not spaghetti_file.exists():
            print(f"⚠️  {sample_name}: Missing file(s)")
            results["failures"].append({
                "sample": sample_name,
                "reason": "Missing file(s)"
            })
            continue
        
        results["total_samples"] += 1
        print(f"Analyzing {sample_name}...", end=" ")
        try:
            normal_result = compile_and_collect_warnings(str(normal_file))
            normal_score = normal_result["badness_score"]
        except Exception as e:
            print(f"❌ (Error in normal: {e})")
            results["failures"].append({
                "sample": sample_name,
                "reason": f"Error analyzing normal: {e}"
            })
            continue
        try:
            spaghetti_result = compile_and_collect_warnings(str(spaghetti_file))
            spaghetti_score = spaghetti_result["badness_score"]
        except Exception as e:
            print(f"❌ (Error in spaghetti: {e})")
            results["failures"].append({
                "sample": sample_name,
                "reason": f"Error analyzing spaghetti: {e}"
            })
            continue
        
        if spaghetti_score > normal_score:
            status = "passed"
        elif spaghetti_score == normal_score:
            status = "caution"
        else:
            status = "failed"
        
        sample_data = {
            "sample": sample_name,
            "normal_score": round(normal_score, 3),
            "spaghetti_score": round(spaghetti_score, 3),
            "difference": round(spaghetti_score - normal_score, 3),
            "status": status
        }
        
        results["sample_scores"].append(sample_data)
        
        if status == "passed":
            results["passed"] += 1
            print(f"(N:{normal_score:.3f} < S:{spaghetti_score:.3f}, Δ:{spaghetti_score-normal_score:.3f})")
        elif status == "caution":
            results["caution"] += 1
            results["caution_samples"].append({
                "sample": sample_name,
                "score": round(normal_score, 3),
                "reason": "Equal scores - no differentiation detected"
            })
            print(f"(N:{normal_score:.3f} == S:{spaghetti_score:.3f}, Δ:0.000) CAUTION")
        else:
            results["failed"] += 1
            results["failures"].append({
                "sample": sample_name,
                "reason": f"Spaghetti score is LOWER: normal={normal_score:.3f}, spaghetti={spaghetti_score:.3f}"
            })
            print(f"(N:{normal_score:.3f} > S:{spaghetti_score:.3f}, Δ:{spaghetti_score-normal_score:.3f}) FAILED")
    
    print()
    print("=" * 70)
    print("VALIDATION SUMMARY")
    print("=" * 70)
    print(f"Total Samples Tested: {results['total_samples']}")
    print(f"Passed: {results['passed']} ({results['passed']/results['total_samples']*100:.1f}%)")
    print(f"Caution: {results['caution']} ({results['caution']/results['total_samples']*100:.1f}%)")
    print(f"Failed: {results['failed']} ({results['failed']/results['total_samples']*100:.1f}%)")
    print()
    
    if results["caution_samples"]:
        print("CAUTION (Equal Scores):")
        for item in results["caution_samples"]:
            print(f"{item['sample']}: Both scores = {item['score']} - {item['reason']}")
        print()
    
    if results["failures"]:
        print("FAILURES (Spaghetti < Normal):")
        for failure in results["failures"]:
            print(f"{failure['sample']}: {failure['reason']}")
        print()
    
    if results["sample_scores"]:
        scores = results["sample_scores"]
        avg_normal = sum(s["normal_score"] for s in scores) / len(scores)
        avg_spaghetti = sum(s["spaghetti_score"] for s in scores) / len(scores)
        avg_diff = sum(s["difference"] for s in scores) / len(scores)
        
        print("STATISTICS:")
        print(f"  Average Normal Score:    {avg_normal:.3f}")
        print(f"  Average Spaghetti Score: {avg_spaghetti:.3f}")
        print(f"  Average Difference:      {avg_diff:.3f}")
        print()
    
    output_file = "validation_results.json"
    with open(output_file, "w") as f:
        json.dump(results, f, indent=2)
    print(f"Detailed results saved to: {output_file}")
    print()
    
    if results["failed"] == 0:
        if results["caution"] == 0:
            print("ALL SAMPLES PASSED! Dataset is valid.")
        else:
            print(f"No failures, but {results['caution']} samples need attention (equal scores).")
        return True
    else:
        print(f"{results['failed']} SAMPLES FAILED. Spaghetti scores are LOWER than normal!")
        return False


if __name__ == "__main__":
    success = validate_dataset()
    sys.exit(0 if success else 1)
