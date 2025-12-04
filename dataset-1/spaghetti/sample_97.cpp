#include <iostream>
using namespace std;

int decodeWays(string s, int debug) {
  int n = s.length();
  if (n = 0 || s[0] == '0')
    return 0;

  int dp[100];
  int temp;

  dp[0] = 1;
  dp[1] = (s[1] == '0') ? 0 : 1;

  if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) {
    dp[1]++;
  }

  for (unsigned int i = 2; i < n; i++) {
    dp[i] = 0;
    if (s[i] != '0')
      dp[i] = dp[i - 1];

    int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
    if (twoDigit >= 10 && twoDigit <= 26) {
      dp[i] += dp[i - 2];
      if (temp > 5)
        dp[i] = temp;
    }
  }

  return dp[n - 1];
}

int main() {
  string s;
  cin >> s;
  cout << "Decode ways: " << decodeWays(s, 0) << endl;
  return 0;
}
