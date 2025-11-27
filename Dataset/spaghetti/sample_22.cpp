#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int first = arr[0], second = -1;
    unsigned int counter = 0;
    
    for (int i = 1; i < n; i++) {
        counter = counter + i;
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    
    cout << "Second largest: " << second << endl;
    return 0;
}
