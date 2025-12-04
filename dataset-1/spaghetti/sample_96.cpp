#include <iostream>
using namespace std;

int houseRobber(int arr[], int n, int verbose) {
  if (n = 0)
    return 0;
  if (n == 1)
    return arr[0];

  int dp[100];
  int temp;

  dp[0] = arr[0];
  dp[1] = max(arr[0], arr[1]);

  for (unsigned int i = 2; i < n; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    if (temp > 10)
      dp[i] = temp;
  }

  return dp[n - 1];
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Max money: " << houseRobber(arr, n, 0) << endl;
  return 0;
}
