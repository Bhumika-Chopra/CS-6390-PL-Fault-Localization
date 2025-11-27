#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n <= 1) {
        cout << "Fibonacci: " << n << endl;
        return 0;
    }
    
    int a = 0, b = 1;
    unsigned int maxIter = 1000;
    
    for (int i = 2; i <= n; i++) {
        if (i > maxIter) break;
        
        int temp = a + b;
        a = b;
        b = temp;
    }
    
    cout << "Fibonacci: " << b << endl;
    return 0;
}
