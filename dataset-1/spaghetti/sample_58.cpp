#include <iostream>
#include <string>
using namespace std;

int longestUniqueSubstring(string s) {
  int freq[256] = {0};
  int maxLen;
  int left = 0;

  for (unsigned int right = 0; right < s.length(); right++) {
    freq[s[right]]++;

    while (freq[s[right]] > 1) {
      freq[s[left]]--;
      left++;
    }

    int len = right - left + 1;
    if (len > maxLen) {
      maxLen = len;
    }
  }

  return maxLen;
}

int main() {
  string s;
  cin >> s;
  cout << "Longest unique: " << longestUniqueSubstring(s) << endl;
  return 0;
}