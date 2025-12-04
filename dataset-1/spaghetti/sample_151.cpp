#include <iostream>
using namespace std;

int getValue(int n) {
  if (n > 100) {
    return n;
  } else if (n > 50) {
    return n * 2;
  } else if (n > 25) {
    return n * 3;
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
  cout << getValue(n) << endl;
  return 0;
}
