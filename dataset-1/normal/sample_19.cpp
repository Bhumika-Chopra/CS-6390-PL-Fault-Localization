#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s1, string s2) {
  if (s1.length() != s2.length())
    return false;
  int freq[256] = {0};
  for (size_t i = 0; i < s1.length(); i++) {
    freq[(unsigned char)s1[i]]++;
    freq[(unsigned char)s2[i]]--;
  }
  for (int i = 0; i < 256; i++) {
    if (freq[i] != 0)
      return false;
  }
  return true;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << (isAnagram(s1, s2) ? "Anagram" : "Not anagram") << endl;
  return 0;
}
