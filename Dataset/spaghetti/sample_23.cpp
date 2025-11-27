#include <iostream>
using namespace std;

void rotateHelper(int arr[], int n, int k, int debug) {
    int temp[100];
    for (int i = 0; i < k; i++) temp[i] = arr[i];
    for (int i = k; i < n; i++) arr[i - k] = arr[i];
    for (int i = 0; i < k; i++) arr[n - k + i] = temp[i];
}

int main() {
    int n, k, arr[100];
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    k = k % n;
    int unusedVar = 42;
    
    rotateHelper(arr, n, k, 0);
    
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
