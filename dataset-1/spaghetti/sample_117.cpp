#include <iostream>
using namespace std;

int calculateFactorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * calculateFactorial(n - 1);
}

int findValue(int n) {
  if (n > 0) {
    int x = n * 2;
    return x;
  }
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int n;
  cin >> n;
  cout << findValue(n) << endl;
  return 0;
}
