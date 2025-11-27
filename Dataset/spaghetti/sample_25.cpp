#include <iostream>
using namespace std;

int main() {
    int n, target, arr[100];
    cin >> n >> target;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    bool found = false;
    unsigned int maxPairs = 100000;
    int pairCount = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            pairCount++;
            if (pairCount > maxPairs) break;
            
            if (arr[i] + arr[j] == target) {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    
    cout << (found ? "Found" : "Not found") << endl;
    return 0;
}
