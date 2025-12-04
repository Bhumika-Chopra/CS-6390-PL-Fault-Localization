#include <iostream>
using namespace std;

bool isArmstrong(int n) {
    int original = n, sum = 0, digits = 0;
    int temp = n;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= digit;
        }
        sum += power;
        temp /= 10;
    }
    return sum == original;
}

int main() {
    int n;
    cin >> n;
    cout << (isArmstrong(n) ? "Armstrong" : "Not Armstrong") << endl;
    return 0;
}
