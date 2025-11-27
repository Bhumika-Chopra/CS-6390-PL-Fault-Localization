#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int dp[1000];
  dp[1] = 0;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    int check;
    if (check = i % 2) {
      if (dp[i / 2] + 1 < dp[i]) {
        dp[i] = dp[i / 2] + 1;
      }
    }
    if (i % 3 == 0) {
      if (dp[i / 3] + 1 < dp[i]) {
        dp[i] = dp[i / 3] + 1;
      }
    }
  }

  cout << "Min steps: " << dp[n] << endl;
  return 0;
}
