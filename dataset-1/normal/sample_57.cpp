#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;
    
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    
    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n)) return -1;
    }
    
    if (arr[prev] == x) return prev;
    return -1;
}

int main() {
    int n, x, arr[100];
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int result = jumpSearch(arr, n, x);
    cout << (result != -1 ? "Found" : "Not found") << endl;
    return 0;
}