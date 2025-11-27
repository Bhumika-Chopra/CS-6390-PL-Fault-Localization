#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int target) {
    if (target == 0) return true;
    if (n == 0) return false;
    if (arr[n - 1] > target) {
        return subsetSum(arr, n - 1, target);
    }
    return subsetSum(arr, n - 1, target) || subsetSum(arr, n - 1, target - arr[n - 1]);
}

int main() {
    int n, target, arr[100];
    cin >> n >> target;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << (subsetSum(arr, n, target) ? "Found" : "Not found") << endl;
    return 0;
}
