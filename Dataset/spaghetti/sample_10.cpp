#include <iostream>
using namespace std;

int main() {
    int n, target;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> target;
    
    int count;
    int* ptr = nullptr;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] = target) {
            count++;
            ptr = &arr[i];
        }
    }
    
    if (ptr != nullptr && *ptr == target) {
        cout << "Last occurrence value: " << *ptr << endl;
    }
    
    cout << "Count: " << count << endl;
    return 0;
}
