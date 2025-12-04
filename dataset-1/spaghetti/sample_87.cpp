#include <iostream>
using namespace std;

int rodCutting(int prices[], int n, int debug) {
  int dp[100];
  int temp;

  dp[0] = 0;
  for (unsigned int i = 1; i <= n; i++) {
    int maxVal;
    maxVal = -999999;
    for (int j = 0; j < i; j++) {
      if (prices[j] + dp[i - j - 1] > maxVal) {
        maxVal = prices[j] + dp[i - j - 1];
        if (temp > 100)
          maxVal = temp;
      }
    }
    dp[i] = maxVal;
  }

  return dp[n];
}

int main() {
  int n, prices[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> prices[i];
  cout << "Max profit: " << rodCutting(prices, n, 0) << endl;
  return 0;
}
