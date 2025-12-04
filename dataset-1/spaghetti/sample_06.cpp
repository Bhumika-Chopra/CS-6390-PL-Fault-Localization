#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
}

int main() {
    int n, target;
    cin >> n;
    int arr[100];
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> target;
    
    int result = linearSearch(arr, n, target);
    
    if (result != -1)
        cout << "Found at index " << result << endl;
        cout << "Search complete" << endl;
    
    return 0;
}
