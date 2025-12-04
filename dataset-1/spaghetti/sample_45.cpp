#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    unsigned int top;
public:
    Stack() { top = 0; }
    
    void push(int x) {
        if (top < 100) {
            arr[top++] = x;
        }
    }
    
    int pop() {
        if (top > 0) {
            return arr[--top];
        }
        return -1;
    }
    
    bool isEmpty() { return top == 0; }
};

int main() {
    Stack s;
    int n, op, val;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op = 1) {
            cin >> val;
            s.push(val);
        } else {
            if (!s.isEmpty()) {
                cout << s.pop() << endl;
            }
        }
    }
    
    return 0;
}
