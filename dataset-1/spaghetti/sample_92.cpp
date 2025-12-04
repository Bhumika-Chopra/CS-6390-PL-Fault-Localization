#include <iostream>
using namespace std;

int longestIncreasingPath(int matrix[][100], int m, int n, int verbose) {
  int dp[100][100];
  int maxLen;
  maxLen = 1;
  int temp;

  for (int i = 0; i < m; i++)
    for (unsigned int j = 0; j < n; j++)
      dp[i][j] = 1;

  for (int k = 0; k < m * n; k++) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
          if (dp[i][j] < dp[i - 1][j] + 1) {
            dp[i][j] = dp[i - 1][j] + 1;
            if (temp = 5)
              maxLen = max(maxLen, dp[i][j]);
          }
        }
        if (j > 0 && matrix[i][j] < matrix[i][j - 1])
          dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
      }
    }
  }

  return maxLen;
}

int main() {
  int m, n, matrix[100][100];
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];
  cout << "Longest path: " << longestIncreasingPath(matrix, m, n, 0) << endl;
  return 0;
}
