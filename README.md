# Automated Detection of Code Complexity Hotspots using AST and Compiler Feedback

## Project Proposal

**Title:** Automated Detection of Code Complexity Hotspots using AST and Compiler Feedback  
**Team Members:**  
- Bhumika Chopra (bchopra9@gatech.edu)  
- Bhawna Kumari (bkumari3@gatech.edu)  
- Ruchika Shirsath (rshirsath3@gatech.edu)  
- Shashwata Roy (sroy389@gatech.edu)

---

## 1. Problem Statement

Modern software systems are large, complex, and continuously evolving. As programs grow, developers often struggle with maintaining and debugging them due to “spaghetti code” — regions that are deeply nested, highly coupled, or structurally complex albeit correct. Such code tends to be error-prone, increasing maintenance costs and reducing overall software reliability.

Existing fault localization (FL) techniques can identify erroneous statements or functions after bugs occur, but they typically depend on precise test coverage, limiting their pre-emptiveness. Meanwhile, static analysis tools (e.g., compiler warnings, linters) detect anti-patterns but often produce false positives and generally lack prioritization.

There is a missing link between compiler-driven structural analysis and pre-emptive fault prediction; we currently lack automated, interpretable tools that can identify potentially error-prone regions before failures occur.

---

## 2. Aim and Hypothesis

**Aim:**  
To identify and rank error-prone (“spaghetti”) code regions using metrics derived from Abstract Syntax Trees (AST) and compiler diagnostics. We will compare our model and metrics with existing literature and baselines.

**Core Hypothesis:**  
Code regions exhibiting high structural complexity in their AST representation, when combined with appropriate compiler diagnostic signals, are significantly more likely to contain smells and represent high-risk areas in code.

---

## 3. Literature Review (Summary)

Recent research into proactive fault prediction utilizes Abstract Syntax Trees (ASTs) across multiple paradigms.

- **Rule-based frameworks** such as the C++ tool *CLEAN++* demonstrate the scalability of AST traversal for detecting predefined code smells, validated across dozens of open-source projects.
- **Learning-based models**, such as Yang et al. (2024), introduce sophisticated feature sets—including structural, syntactic, and semantic AST metrics—to create flexible smell detectors. This approach provides our core feature set and serves as a benchmark.

However, both paradigms rely on code smells as an indirect proxy for software faults. A key research gap is the lack of integration with direct signals of potential defects, such as compiler diagnostics.

Our work addresses this gap by fusing advanced AST metrics (Yang et al.) with compiler diagnostics in a scalable analysis pipeline inspired by CLEAN++. This approach shifts from smell detection to proactive fault-risk analysis. A limitation is that the framework applies only to compiled languages and requires compilation during preprocessing.

---

## 4. Evaluation Plan & Proposed Methodology

### **AST Metric Extraction**
Extract structural, syntactic, and semantic metrics following the methodology of Yang et al. (2024).

### **Compiler Diagnostics Collection (Novel Contribution)**
Collect fine-grained compiler diagnostics such as warnings, optimization hints, and static analysis reports. Each diagnostic will be encoded by:
- Type  
- Frequency  
- Severity  

Metrics will be normalized by code size for comparability.

### **Composite Risk Scoring**
Combine AST metrics and compiler diagnostics into a weighted composite score. Feature weights will be determined experimentally.

### **Benchmarking and Evaluation**
Compare the framework against existing techniques such as:
- Hotspot Detection (DiscoPop)
- AST-based model from *Expert Systems with Applications* (2024)

Evaluation metrics:
- **Precision**
- **Recall**
- **F1-score**

---

## 7. References

- Mashiach et al. (2023). *CLEAN++: Static Detection of Code Smells Using Clang AST*. MSR 2023.  
- Yang et al. (2024). *Fusion Learning for Code Smell Detection Using AST Metrics and Semantic Embeddings*. Expert Systems with Applications.  
- **Hotspot Detection** – DiscoPop Project  
- **Defects4J** Dataset  
- **BugsInPy** Dataset  
