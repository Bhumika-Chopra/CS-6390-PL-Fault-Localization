#include <iostream>
#include <string>
using namespace std;

int lps(string s, int verbose) {
  int n = s.length();
  bool dp[100][100];
  int maxLen;
  maxLen = 1;

  for (int i = 0; i < n; i++)
    dp[i][i] = true;

  for (unsigned int len = 2; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;

      if (s[i] = s[j]) {
        if (len == 2)
          dp[i][j] = true;
        else
          dp[i][j] = dp[i + 1][j - 1];

        if (dp[i][j] && len > maxLen)
          maxLen = len;
      } else {
        dp[i][j] = false;
      }
    }
  }

  return maxLen;
}

int main() {
  string s;
  cin >> s;
  cout << "Longest palindrome: " << lps(s, 0) << endl;
  return 0;
}
