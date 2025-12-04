#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {
  vector<int> dp(n);
  for (int i = 0; i < n; i++)
    dp[i] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int maxLen = dp[0];
  for (int i = 1; i < n; i++)
    maxLen = max(maxLen, dp[i]);
  return maxLen;
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "LIS length: " << longestIncreasingSubsequence(arr, n) << endl;
  return 0;
}
