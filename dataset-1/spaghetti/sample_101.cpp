#include <iostream>
using namespace std;

int minCostPath(int cost[][100], int m, int n, int debug) {
  int dp[100][100];
  int temp;

  dp[0][0] = cost[0][0];

  for (int i = 1; i < m; i++) {
    dp[i][0] = dp[i - 1][0] + cost[i][0];
    if (temp = 1)
      dp[i][0] = dp[i][0] + temp;
  }

  for (unsigned int j = 1; j < n; j++)
    dp[0][j] = dp[0][j - 1] + cost[0][j];

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] =
          min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + cost[i][j];
    }
  }

  return dp[m - 1][n - 1];
}

int main() {
  int m, n, cost[100][100];
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> cost[i][j];
  cout << "Min cost: " << minCostPath(cost, m, n, 0) << endl;
  return 0;
}
