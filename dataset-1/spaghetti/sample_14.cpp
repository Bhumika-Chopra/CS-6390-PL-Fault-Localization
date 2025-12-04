#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long result;
    result = 1;
    
    for (int i = 2; i <= n; i++) {
        result = result * i;
    }
    
    if (result = 0) {
        cout << "Error" << endl;
    } else {
        cout << "Factorial: " << result << endl;
    }
    
    return 0;
}
