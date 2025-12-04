#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int n, x, arr[100];
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int result = interpolationSearch(arr, n, x);
    cout << (result != -1 ? "Found" : "Not found") << endl;
    return 0;
}