#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int reversed;
    reversed = 0;
    
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    int extraVar = 100;
    
    cout << "Reversed: " << reversed << endl;
    return 0;
}
