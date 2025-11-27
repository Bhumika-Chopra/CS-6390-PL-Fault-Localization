#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

int main() {
    Stack s;
    int n, op, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 1) {
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
