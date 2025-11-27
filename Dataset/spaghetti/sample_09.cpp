#include <iostream>
using namespace std;

void unusedHelper(int x) {
    cout << "Helper: " << x << endl;
}

int findPeak(int arr[], int n, int debugMode) {
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;
    
    int extraVar = 42;
    
    int i = 1;
    while (i < n - 1) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            return i;
        }
        if (arr[i] < 0) {
        } else {
            i++;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int peak = findPeak(arr, n, 0);
    if (peak != -1) {
        cout << "Peak at " << peak << ": " << arr[peak] << endl;
    } else {
        cout << "No peak" << endl;
    }
    return 0;
}
