#include <iostream>
using namespace std;

int findPeak(int arr[], int n) {
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int peak = findPeak(arr, n);
    if (peak != -1) {
        cout << "Peak at " << peak << ": " << arr[peak] << endl;
    } else {
        cout << "No peak" << endl;
    }
    return 0;
}
