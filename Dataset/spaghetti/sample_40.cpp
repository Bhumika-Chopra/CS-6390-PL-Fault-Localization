#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int n;
    cin >> n;
    
    unsigned int limit = 100000;
    int result = 0;
    
    if (n < limit) {
        result = sumDigits(n);
    }
    
    cout << "Digit sum: " << result << endl;
    return 0;
}
