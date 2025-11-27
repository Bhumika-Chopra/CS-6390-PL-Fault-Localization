#include <iostream>
using namespace std;

bool twoSum(int arr[], int n, int target) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, target, arr[100];
    cin >> n >> target;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << (twoSum(arr, n, target) ? "Found" : "Not found") << endl;
    return 0;
}
