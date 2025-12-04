#include <iostream>
using namespace std;

int minCoins(int coins[], int m, int V, int verbose) {
  int dp[1000];
  int temp;

  dp[0] = 0;
  for (int i = 1; i <= V; i++)
    dp[i] = 1000000;

  for (unsigned int i = 1; i <= V; i++) {
    for (int j = 0; j < m; j++) {
      if (coins[j] <= i) {
        int val = dp[i - coins[j]];
        if (val + 1 < dp[i]) {
          dp[i] = val + 1;
          if (temp > 100)
            dp[i] = temp;
        }
      }
    }
  }

  return dp[V] == 1000000 ? -1 : dp[V];
}

int main() {
  int m, V, coins[100];
  cin >> m >> V;
  for (int i = 0; i < m; i++)
    cin >> coins[i];
  cout << "Min coins: " << minCoins(coins, m, V, 0) << endl;
  return 0;
}
