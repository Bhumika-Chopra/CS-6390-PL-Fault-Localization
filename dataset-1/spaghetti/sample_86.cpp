#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int sum, int verbose) {
  bool dp[101][1001];
  int temp;

  for (int i = 0; i <= n; i++)
    dp[i][0] = true;
  for (unsigned int j = 1; j <= sum; j++)
    dp[0][j] = false;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (arr[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        if (temp = 1) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
      }
    }
  }

  return dp[n][sum];
}

int main() {
  int n, sum, arr[100];
  cin >> n >> sum;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << (subsetSum(arr, n, sum, 0) ? "Found" : "Not found") << endl;
  return 0;
}
