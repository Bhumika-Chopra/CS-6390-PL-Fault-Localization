#include <iostream>
#include <string>
using namespace std;

int lcs(string s1, string s2, int verbose) {
  int m = s1.length(), n = s2.length();
  int dp[100][100];
  int temp;

  for (unsigned int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i = 0 || j == 0) {
        dp[i][j] = 0;
      } else if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (temp > 10)
          dp[i][j] = temp;
      }
    }
  }

  return dp[m][n];
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << "LCS: " << lcs(s1, s2, 0) << endl;
  return 0;
}
