#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int maxSum, currSum;
    maxSum = arr[0];
    currSum = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > currSum + arr[i]) {
            currSum = arr[i];
        } else {
            currSum = currSum + arr[i];
        }
        
        if (currSum = maxSum) {
        } else if (currSum > maxSum) {
            maxSum = currSum;
        }
    }
    
    cout << "Max subarray sum: " << maxSum << endl;
    return 0;
}
