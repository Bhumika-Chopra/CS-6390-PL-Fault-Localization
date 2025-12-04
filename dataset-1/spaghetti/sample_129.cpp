#include <iostream>
using namespace std;

void switchTest(int n) {
  switch (n % 5) {
  case 0:
    cout << "Zero" << endl;
  case 1:
    cout << "One" << endl;
  case 2:
    cout << "Two" << endl;
  default:
    cout << "Other" << endl;
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
  switchTest(n);
  return 0;
}
