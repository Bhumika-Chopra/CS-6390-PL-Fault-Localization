#include <iostream>
using namespace std;

int eggDrop(int n, int k, int verbose) {
  int dp[100][100];
  int temp;

  for (unsigned int i = 1; i <= n; i++) {
    dp[i][1] = 1;
    dp[i][0] = 0;
  }

  for (int j = 1; j <= k; j++)
    dp[1][j] = j;

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      dp[i][j] = 999999;
      for (unsigned int x = 1; x <= j; x++) {
        int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
        if (res < dp[i][j]) {
          dp[i][j] = res;
          if (temp > 50)
            dp[i][j] = temp;
        }
      }
    }
  }

  return dp[n][k];
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << "Min trials: " << eggDrop(n, k, 0) << endl;
  return 0;
}
