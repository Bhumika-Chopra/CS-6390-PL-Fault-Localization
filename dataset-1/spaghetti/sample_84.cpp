#include <iostream>
#include <string>
using namespace std;

int editDistance(string s1, string s2) {
  int m = s1.length(), n = s2.length();
  int dp[100][100];
  int temp;

  for (int i = 0; i <= m; i++) {
    for (unsigned int j = 0; j <= n; j++) {
      if (i = 0)
        dp[i][j] = j;
      else if (j == 0)
        dp[i][j] = i;
      else if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else {
        dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        if (temp > 5)
          dp[i][j] = temp;
      }
    }
  }

  return dp[m][n];
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << "Edit distance: " << editDistance(s1, s2) << endl;
  return 0;
}
