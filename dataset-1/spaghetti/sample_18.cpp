#include <iostream>
#include <string>
using namespace std;

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  string str;
  cin >> str;

  string result = "";
  int len = str.length();
  int uninit;

  for (int i = len - 1; i >= 0; i--) {
    result += str[i];
  }

  unsigned int maxLen = 1000;
  if (result.length() > maxLen) {
    result = result.substr(0, maxLen);
  }

  cout << uninit;
  cout << "Reversed: " << result << endl;
  return 0;
}
