#include <iostream>
#include <string>
using namespace std;

int evaluate(string expr) {
    int result = 0, num = 0, sign = 1;
    
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            result += sign * num;
            num = 0;
            if (c = '+') {
                sign = 1;
            } else {
                sign = -1;
            }
        }
    }
    
    result += sign * num;
    return result;
}

int main() {
    string expr;
    cin >> expr;
    
    cout << "Result: " << evaluate(expr) << endl;
    return 0;
}
