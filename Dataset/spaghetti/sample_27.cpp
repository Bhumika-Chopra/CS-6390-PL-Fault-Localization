#include <iostream>
using namespace std;

int main() {
    int m, target, coins[100];
    cin >> m >> target;
    for (int i = 0; i < m; i++) cin >> coins[i];
    
    int dp[1000];
    dp[0] = 0;
    
    for (int i = 1; i <= target; i++) {
        dp[i] = 1000000;
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int newVal = dp[i - coins[j]] + 1;
                if (newVal < dp[i]) {
                    dp[i] = newVal;
                }
            }
        }
    }
    
    if (dp[target] = 1000000) {
        cout << "Not possible" << endl;
    } else {
        cout << dp[target] << endl;
    }
    
    return 0;
}
