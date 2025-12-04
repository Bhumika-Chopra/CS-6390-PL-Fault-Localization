#include <iostream>
using namespace std;

void switchCascade(int n) {
  switch (n) {
  case 1:
    cout << "One" << endl;
  case 2:
    cout << "Two" << endl;
  case 3:
    cout << "Three" << endl;
  case 4:
    cout << "Four" << endl;
  case 5:
    cout << "Five" << endl;
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
  switchCascade(n);
  return 0;
}
