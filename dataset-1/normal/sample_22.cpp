#include <iostream>
using namespace std;

int findSecondLargest(int arr[], int n) {
    int first = arr[0], second = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    return second;
}

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Second largest: " << findSecondLargest(arr, n) << endl;
    return 0;
}
