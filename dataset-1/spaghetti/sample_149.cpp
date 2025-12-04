#include <iostream>
using namespace std;

int compute(int x) {
  int y;
  int z;

  if (x > 0) {
    y = x * 2;
  }

  if (x > 10) {
    z = y + 5;
  }

  return z;
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
  cout << compute(n) << endl;
  return 0;
}
