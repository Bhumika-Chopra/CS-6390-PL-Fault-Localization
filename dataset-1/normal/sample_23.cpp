#include <iostream>
using namespace std;

void rotateLeft(int arr[], int n, int k) {
    k = k % n;
    int temp[100];
    for (int i = 0; i < k; i++) temp[i] = arr[i];
    for (int i = k; i < n; i++) arr[i - k] = arr[i];
    for (int i = 0; i < k; i++) arr[n - k + i] = temp[i];
}

int main() {
    int n, k, arr[100];
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    rotateLeft(arr, n, k);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
