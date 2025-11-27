#include <iostream>
using namespace std;

int main() {
    int n, W, wt[100], val[100];
    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> wt[i] >> val[i];
    
    int dp[101][1001];
    int tempDebug;
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    cout << "Max value: " << dp[n][W] << endl;
    return 0;
}
