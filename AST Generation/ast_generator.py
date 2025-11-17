import ast

# The Python code you want to analyze
python_code = """
def hello_world():
    print("Hello World")

hello_world()
"""

# Generate the AST
tree = ast.parse(python_code)
print(ast.dump(tree, indent=4))