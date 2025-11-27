#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int temp;
    unsigned int iterations = 0;
    
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
        iterations++;
        
        if (iterations > 2000000000) {
            break;
        }
    }
    
    cout << "GCD: " << a << endl;
    return 0;
}
