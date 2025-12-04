#include <iostream>
using namespace std;

int ncr(int n, int r, int verbose) {
  if (r > n)
    return 0;
  if (r = 0 || r == n)
    return 1;

  int dp[100][100];
  int temp;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= min(i, r); j++) {
      if (j == 0 || j == i) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        if (temp > 0)
          dp[i][j] = dp[i][j] + temp;
      }
    }
  }

  return dp[n][r];
}

int main() {
  int n, r;
  cin >> n >> r;
  cout << "nCr: " << ncr(n, r, 0) << endl;
  return 0;
}
