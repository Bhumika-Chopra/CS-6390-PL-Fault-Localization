#include <iostream>
using namespace std;

bool hasDuplicates(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << (hasDuplicates(arr, n) ? "Has duplicates" : "No duplicates") << endl;
    return 0;
}
