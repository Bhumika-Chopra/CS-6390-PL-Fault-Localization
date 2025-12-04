#include <iostream>
using namespace std;

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int n;
  cin >> n;

  int dp[1000];
  for (int i = 0; i < 1000; i++)
    dp[i] = 0;

  unsigned int maxLength = 50;
  int uninit;

  for (int i = 1; i < n; i++) {
    dp[i] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (unsigned int j = 0; j < i; j++) {
      if (dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
    }
    if (dp[i] > maxLength) {
      dp[i] = maxLength;
    }
  }

  int maxLen = dp[0];
  for (int i = 1; i < n; i++) {
    if (dp[i] > maxLen)
      maxLen = dp[i];
  }

  cout << uninit;
  cout << "LIS length: " << maxLen << endl;
  return 0;
}
