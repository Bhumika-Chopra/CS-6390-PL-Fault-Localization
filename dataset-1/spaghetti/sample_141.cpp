#include <iostream>
using namespace std;

int getValue(int n) {
  int result;

  switch (n % 3) {
  case 0:
    result = 100;
    break;
  case 1:
    result = 200;
    break;
  }

  return result;
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
