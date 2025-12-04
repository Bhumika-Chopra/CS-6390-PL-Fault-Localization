import clang.cindex
import os
import sys
import json

# ---------------------------------------------------------------------
# 1. Setup libclang (Adjust paths if needed)
# ---------------------------------------------------------------------
def try_load_clang():
    possible_paths = [
        "/opt/homebrew/opt/llvm/lib/libclang.dylib",
        "/usr/local/opt/llvm/lib/libclang.dylib",
        "/Library/Developer/CommandLineTools/usr/lib/libclang.dylib",
    ]
    for p in possible_paths:
        if os.path.exists(p):
            clang.cindex.Config.set_library_file(p)
            return

try_load_clang()

# ---------------------------------------------------------------------
# 2. Metrics Calculator
# ---------------------------------------------------------------------
class ASTMetrics:
    def __init__(self, target_filename):
        # Store absolute path to ensure we only count nodes in THIS file
        self.target_file = os.path.abspath(target_filename)
        
        # --- Counters ---
        self.node_count = 0
        self.max_depth = 0
        self.max_param_length = 0
        self.node_kinds = set() # To track unique kinds for repetition rate
        
        self.total_children_count = 0
        self.nodes_with_children = 0
        
        self.cyclomatic_complexity = 1
        
        # Syntax Counters
        self.cnt_if = 0
        self.cnt_binary = 0
        self.cnt_method_call = 0
        self.cnt_assignment = 0
        self.cnt_return = 0
        
        # Semantic Counters
        self.cnt_while = 0
        self.cnt_for = 0
        self.cnt_if_else = 0 # Heuristic: If node has 3+ children

    def get_binary_type(self, node):
        """Distinguish '=' (Assignment) from '+' (Binary Op)"""
        try:
            # Check the operator token
            tokens = list(node.get_tokens())
            for t in tokens:
                if t.spelling in ["=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="]:
                    return "ASSIGNMENT"
        except:
            pass
        return "BINARY_OP"

    def traverse(self, node, depth=0):
        # -------------------------------------------------------
        # FILTER: Ignore System Headers (iostream, vector, etc.)
        # -------------------------------------------------------
        if node.location.file:
            # If the node comes from a file that is NOT our target file, skip it.
            if os.path.abspath(node.location.file.name) != self.target_file:
                return

        # 1. General Node Stats
        self.node_count += 1
        self.node_kinds.add(node.kind)
        if depth > self.max_depth:
            self.max_depth = depth

        # 2. Branching Factor Stats
        children = list(node.get_children())
        if children:
            self.total_children_count += len(children)
            self.nodes_with_children += 1

        # 3. Max Parameter Length (Check Function Declarations)
        if node.kind in [clang.cindex.CursorKind.FUNCTION_DECL, 
                         clang.cindex.CursorKind.CXX_METHOD]:
            params = [c for c in children if c.kind == clang.cindex.CursorKind.PARM_DECL]
            if len(params) > self.max_param_length:
                self.max_param_length = len(params)

        # 4. Syntax & Semantic Logic
        k = node.kind
        
        # --- IF Statements ---
        if k == clang.cindex.CursorKind.IF_STMT:
            self.cnt_if += 1
            self.cyclomatic_complexity += 1
            # Heuristic: If it has 3 children (Condition, Then, Else), it's an If-Else
            if len(children) >= 3:
                self.cnt_if_else += 1
        
        # --- Loops ---
        elif k == clang.cindex.CursorKind.WHILE_STMT:
            self.cnt_while += 1
            self.cyclomatic_complexity += 1
        elif k == clang.cindex.CursorKind.FOR_STMT:
            self.cnt_for += 1
            self.cyclomatic_complexity += 1
        elif k in [clang.cindex.CursorKind.DO_STMT, clang.cindex.CursorKind.CASE_STMT]:
            self.cyclomatic_complexity += 1

        # --- Operations ---
        elif k == clang.cindex.CursorKind.BINARY_OPERATOR:
            op_type = self.get_binary_type(node)
            if op_type == "ASSIGNMENT":
                self.cnt_assignment += 1
            else:
                self.cnt_binary += 1
        
        elif k == clang.cindex.CursorKind.CALL_EXPR:
            self.cnt_method_call += 1
            
        elif k == clang.cindex.CursorKind.RETURN_STMT:
            self.cnt_return += 1

        # Recurse
        for c in children:
            self.traverse(c, depth + 1)

    def get_results(self):
        # Calculate Averages/Rates
        avg_branching = 0
        if self.nodes_with_children > 0:
            avg_branching = self.total_children_count / self.nodes_with_children
            
        repetition_rate = 0
        if self.node_count > 0:
            # Rate = 1 - (Unique Types / Total Nodes)
            repetition_rate = 1.0 - (len(self.node_kinds) / self.node_count)

        return {
            "Structural metrics": {
                "Branching factor (Average)": round(avg_branching, 2),
                "Cyclomatic complexity": self.cyclomatic_complexity,
                "treeDepth": self.max_depth,
                "no of nodes": self.node_count,
                "maxParameter List length": self.max_param_length,
                "node repetition rate": round(repetition_rate, 2)
            },
            "syntax metrics": {
                "no of if statements": self.cnt_if,
                "no of binary operation": self.cnt_binary,
                "no of method invocation": self.cnt_method_call,
                "no of assignment": self.cnt_assignment,
                "no of return statement": self.cnt_return
            },
            "semantic metrics": {
                "if true (Pure If)": self.cnt_if - self.cnt_if_else,
                "if-else": self.cnt_if_else,
                "while loops": self.cnt_while,
                "for loops": self.cnt_for
            }
        }

# ---------------------------------------------------------------------
# 3. Main
# ---------------------------------------------------------------------
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python generate_ast_metrics.py <cpp_file>")
        sys.exit(1)
    
    filename = sys.argv[1]
    
    # Check if file exists
    if not os.path.exists(filename):
        print(f"Error: File '{filename}' not found.")
        sys.exit(1)

    index = clang.cindex.Index.create()
    tu = index.parse(filename, args=["-std=c++17"])
    
    metrics = ASTMetrics(filename)
    metrics.traverse(tu.cursor)
    
    print(json.dumps(metrics.get_results(), indent=2))