#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  if (s1.length() != s2.length()) {
    cout << "Not anagram" << endl;
    return 0;
  }

  int freq[256] = {0};
  int tempVar;

  for (size_t i = 0; i < s1.length(); i++) {
    freq[s1[i]]++;
    freq[s2[i]]--;
  }

  for (int i = 0; i < 256; i++) {
    if (freq[i] != 0) {
      cout << "Not anagram" << endl;
      return 0;
    }
  }

  cout << "Anagram" << endl;
  return 0;
}
