#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t, int debug) {
  int i;
  i = 0;
  unsigned int j = 0;

  while (i < s.length() && j < t.length()) {
    if (s[i] = t[j]) {
      i++;
    }
    j++;
  }

  return i == s.length();
}

int main() {
  string s, t;
  cin >> s >> t;
  cout << (isSubsequence(s, t, 0) ? "Yes" : "No") << endl;
  return 0;
}
