import clang.cindex
import os
import sys
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
            return

try_load_clang()

class ASTMetrics:
    LOOP_KINDS = [
        clang.cindex.CursorKind.FOR_STMT,
        clang.cindex.CursorKind.WHILE_STMT,
        clang.cindex.CursorKind.DO_STMT
    ]
    BRANCH_KINDS = [
        clang.cindex.CursorKind.IF_STMT,
        clang.cindex.CursorKind.SWITCH_STMT,
        clang.cindex.CursorKind.CASE_STMT
    ]
    EXPRESSION_KINDS = [
        clang.cindex.CursorKind.BINARY_OPERATOR,
        clang.cindex.CursorKind.UNARY_OPERATOR,
        clang.cindex.CursorKind.CALL_EXPR,
        clang.cindex.CursorKind.DECL_REF_EXPR,
        clang.cindex.CursorKind.CONDITIONAL_OPERATOR,
        clang.cindex.CursorKind.CSTYLE_CAST_EXPR,
    ]

    def __init__(self):
        self.node_count = 0
        self.max_depth = 0
        self.total_branches = 0
        self.total_loops = 0
        self.total_expr = 0
        self.total_cyclomatic = 1  
        self.total_paths = 0
        self.total_branching_factor = 0
        self.total_nodes_with_children = 0

    def traverse(self, node, depth=0):
        self.node_count += 1
        if depth > self.max_depth:
            self.max_depth = depth

        children = list(node.get_children())
        if children:
            self.total_branching_factor += len(children)
            self.total_nodes_with_children += 1

        kind = node.kind

        if kind in self.LOOP_KINDS:
            self.total_loops += 1
            self.total_cyclomatic += 1
        if kind in self.BRANCH_KINDS:
            self.total_branches += 1
            self.total_cyclomatic += 1
        if kind in self.EXPRESSION_KINDS:
            self.total_expr += 1

        longest_child_path = 0
        for c in children:
            path_len = self.traverse(c, depth + 1)
            if path_len > longest_child_path:
                longest_child_path = path_len

        return 1 + longest_child_path 

    def compute(self, root_node):
        longest_path = self.traverse(root_node)
        avg_branching = (self.total_branching_factor / self.total_nodes_with_children
                         if self.total_nodes_with_children else 0)
        return {
            "AST_node_count": self.node_count,
            "Depth_of_tree": self.max_depth,
            "Cyclomatic_complexity": self.total_cyclomatic,
            "Number_of_loops": self.total_loops,
            "Number_of_branches": self.total_branches,
            "Number_of_expressions": self.total_expr
        }

def get_function_metrics(root_node, source_filename):
    function_stats = {}

    FUNCTION_KINDS = [
        clang.cindex.CursorKind.FUNCTION_DECL,
        clang.cindex.CursorKind.CXX_METHOD,
        clang.cindex.CursorKind.CONSTRUCTOR,
        clang.cindex.CursorKind.DESTRUCTOR
    ]

    for node in root_node.get_children():
        if node.kind in FUNCTION_KINDS:

            if node.location.file and node.location.file.name == source_filename:
                
                metrics_engine = ASTMetrics()
                stats = metrics_engine.compute(node)
                
                function_stats[node.spelling] = stats

    return function_stats

def generate_ast(filename):
    index = clang.cindex.Index.create()
    tu = index.parse(filename, args=["-std=c++17"])
    return tu.cursor

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python ast_metrics.py <cpp_file>")
        exit(1)

    cpp_file = os.path.abspath(sys.argv[1]) 
    root = generate_ast(cpp_file)

    global_metrics = ASTMetrics().compute(root)

    func_metrics = get_function_metrics(root, cpp_file)

    output = {
        "global_metrics": global_metrics,
        "function_metrics": func_metrics
    }

    print(json.dumps(output, indent=2))