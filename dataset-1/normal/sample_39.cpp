#include <iostream>
using namespace std;

int power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    int half = power(base, exp / 2);
    if (exp % 2 == 0) {
        return half * half;
    } else {
        return base * half * half;
    }
}

int main() {
    int base, exp;
    cin >> base >> exp;
    cout << "Result: " << power(base, exp) << endl;
    return 0;
}
