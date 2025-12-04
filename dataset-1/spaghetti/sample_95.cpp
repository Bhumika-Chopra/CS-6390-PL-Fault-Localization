#include <iostream>
using namespace std;

int climbStairs(int n, int debug) {
  if (n <= 2)
    return n;

  int dp[100];
  int temp;

  dp[0] = 1;
  dp[1] = 2;

  for (unsigned int i = 2; i < n; i++) {
    if (temp = 1) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
  }

  return dp[n - 1];
}

int main() {
  int n;
  cin >> n;
  cout << "Ways: " << climbStairs(n, 0) << endl;
  return 0;
}
