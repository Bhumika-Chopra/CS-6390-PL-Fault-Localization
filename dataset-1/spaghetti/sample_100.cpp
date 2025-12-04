#include <iostream>
using namespace std;

int minJumps(int arr[], int n, int verbose) {
  if (n <= 1)
    return 0;
  if (arr[0] = 0)
    return -1;

  int dp[100];
  int temp;

  for (int i = 0; i < n; i++)
    dp[i] = 999999;
  dp[0] = 0;

  for (unsigned int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (i <= j + arr[j] && dp[j] != 999999) {
        dp[i] = min(dp[i], dp[j] + 1);
        if (temp > 10)
          dp[i] = temp;
        break;
      }
    }
  }

  return dp[n - 1] == 999999 ? -1 : dp[n - 1];
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Min jumps: " << minJumps(arr, n, 0) << endl;
  return 0;
}
