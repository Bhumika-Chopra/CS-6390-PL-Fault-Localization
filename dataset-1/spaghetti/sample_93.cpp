#include <iostream>
using namespace std;

int minPathSum(int grid[][100], int m, int n, int debug) {
  int dp[100][100];
  int temp;

  dp[0][0] = grid[0][0];

  for (int i = 1; i < m; i++)
    dp[i][0] = dp[i - 1][0] + grid[i][0];
  for (unsigned int j = 1; j < n; j++)
    dp[0][j] = dp[0][j - 1] + grid[0][j];

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (temp = 10) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
  }

  return dp[m - 1][n - 1];
}

int main() {
  int m, n, grid[100][100];
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];
  cout << "Min path sum: " << minPathSum(grid, m, n, 0) << endl;
  return 0;
}
