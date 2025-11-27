#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int dp[100];
    for (int i = 0; i < n; i++) dp[i] = 1;
    
    unsigned int maxLength = 50;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (dp[i] > maxLength) {
            dp[i] = maxLength;
        }
    }
    
    int maxLen = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i] > maxLen) maxLen = dp[i];
    }
    
    cout << "LIS length: " << maxLen << endl;
    return 0;
}
