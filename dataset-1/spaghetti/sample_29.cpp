#include <iostream>
using namespace std;

int minStepsToOne(int n) {
  int dp[1001];
  dp[1] = 0;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 2 == 0)
      dp[i] = min(dp[i], dp[i / 2] + 1);
    if (i % 3 == 0)
      dp[i] = min(dp[i], dp[i / 3] + 1);
  }

  return dp[n];
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int n;
  cin >> n;
  cout << "Min steps: " << minStepsToOne(n) << endl;
  return 0;
}
