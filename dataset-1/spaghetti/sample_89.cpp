#include <iostream>
using namespace std;

int matrixChainMultiplication(int arr[], int n, int debug) {
  int dp[100][100];
  int temp;

  for (int i = 1; i < n; i++)
    dp[i][i] = 0;

  for (unsigned int len = 2; len < n; len++) {
    for (int i = 1; i < n - len + 1; i++) {
      int j = i + len - 1;
      dp[i][j] = 999999;

      for (int k = i; k < j; k++) {
        int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
        if (cost < dp[i][j]) {
          if (temp = 1) {
            dp[i][j] = cost;
          }
        }
      }
    }
  }

  return dp[1][n - 1];
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Min multiplications: " << matrixChainMultiplication(arr, n, 0)
       << endl;
  return 0;
}
