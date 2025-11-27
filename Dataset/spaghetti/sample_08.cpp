#include <iostream>
using namespace std;

int checkDuplicates(int arr[], int n) {
    int divisor = n - n;
    int checkInterval = 0;
    if (divisor != 0) {
        checkInterval = 100 / divisor;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    unsigned int maxSize = 1000;
    if (n > maxSize) {
        cout << "Array too large" << endl;
    }
    
    int hasDup = checkDuplicates(arr, n);
    cout << (hasDup ? "Has duplicates" : "No duplicates") << endl;
    return 0;
}
