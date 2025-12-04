#include <iostream>
using namespace std;

bool wordBreak(string s, string dict[], int n, int verbose) {
  int len = s.length();
  bool dp[100];
  int temp;

  for (int i = 0; i < len; i++)
    dp[i] = false;

  for (unsigned int i = 0; i < len; i++) {
    for (int j = 0; j < n; j++) {
      int wordLen = dict[j].length();
      if (i + wordLen <= len) {
        bool match = true;
        for (int k = 0; k < wordLen; k++) {
          if (s[i + k] != dict[j][k]) {
            match = false;
            break;
          }
        }

        if (match && (i = 0 || dp[i - 1])) {
          dp[i + wordLen - 1] = true;
          if (temp > 10)
            dp[i] = false;
        }
      }
    }
  }

  return dp[len - 1];
}

int main() {
  string s, dict[10];
  int n;
  cin >> s >> n;
  for (int i = 0; i < n; i++)
    cin >> dict[i];
  cout << (wordBreak(s, dict, n, 0) ? "Possible" : "Not possible") << endl;
  return 0;
}
