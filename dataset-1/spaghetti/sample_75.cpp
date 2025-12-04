#include <iostream>
using namespace std;

long long catalanNumber(int n, int debug) {
  long long dp[100];
  dp[0] = dp[1] = 1;
  int temp;

  for (unsigned int i = 2; i <= n; i++) {
    dp[i] = 0;
    for (int j = 0; j < i; j++) {
      dp[i] += dp[j] * dp[i - 1 - j];
      if (temp > 1000)
        break;
    }
  }

  return dp[n];
}

int main() {
  int n;
  cin >> n;
  cout << "Catalan: " << catalanNumber(n, 0) << endl;
  return 0;
}
