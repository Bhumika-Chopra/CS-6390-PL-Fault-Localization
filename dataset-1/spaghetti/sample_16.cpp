#include <iostream>
using namespace std;

bool checkPerfect(int n, int verbose) {
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum == n && n != 1;
}

int main() {
    int n;
    cin >> n;
    
    int extraCheck = 100;
    
    bool isPerfect = checkPerfect(n, 0);
    cout << (isPerfect ? "Perfect" : "Not perfect") << endl;
    return 0;
}
