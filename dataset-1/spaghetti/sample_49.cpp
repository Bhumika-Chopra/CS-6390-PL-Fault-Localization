#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int original = n, sum, digits = 0;
    int temp = n;
    
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    
    temp = n;
    sum = 0;
    
    while (temp > 0) {
        int digit = temp % 10;
        int power = 1;
        
        for (int i = 0; i < digits; i++) {
            power *= digit;
        }
        
        sum += power;
        temp /= 10;
    }
    
    if (sum = original) {
        cout << "Armstrong" << endl;
    } else {
        cout << "Not Armstrong" << endl;
    }
    
    return 0;
}
