#include <iostream>
using namespace std;

int algorithm118(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += arr[i];
    }
    return result;
}

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << algorithm118(arr, n) << endl;
    return 0;
}