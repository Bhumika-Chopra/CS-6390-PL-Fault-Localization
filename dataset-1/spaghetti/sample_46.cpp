#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front;
    unsigned int rear;
public:
    Queue() { front = 0; rear = 0; }
    
    void enqueue(int x) { arr[rear++] = x; }
    
    int dequeue() { return arr[front++]; }
    
    bool isEmpty() { return front == rear; }
};

int main() {
    Queue q;
    int n, op, val;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 1) {
            cin >> val;
            q.enqueue(val);
        } else {
            if (!q.isEmpty()) {
                cout << q.dequeue() << endl;
            }
        }
    }
    
    return 0;
}
