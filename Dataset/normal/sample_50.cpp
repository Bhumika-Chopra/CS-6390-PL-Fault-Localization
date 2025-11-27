#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num, den;
    cin >> num >> den;
    int g = gcd(num, den);
    cout << "Simplified: " << num / g << "/" << den / g << endl;
    return 0;
}
