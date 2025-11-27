#include <iostream>
using namespace std;

int main() {
    int n, target;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> target;
    
    int result;
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] = target) {
            result = mid;
            break;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << (result >= 0 ? "Found" : "Not found") << endl;
    return 0;
}
