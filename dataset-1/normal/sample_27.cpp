#include <iostream>
#include <vector>
using namespace std;

int coinChange(int coins[], int m, int target) {
  vector<int> dp(target + 1);
  dp[0] = 0;
  for (int i = 1; i <= target; i++)
    dp[i] = 1e9;
  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < m; j++) {
      if (coins[j] <= i) {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }
  return dp[target] == 1e9 ? -1 : dp[target];
}

int main() {
  int m, target, coins[100];
  cin >> m >> target;
  for (int i = 0; i < m; i++)
    cin >> coins[i];
  int result = coinChange(coins, m, target);
  cout << (result == -1 ? "Not possible" : to_string(result)) << endl;
  return 0;
}
