#include <iostream>
using namespace std;

void multiShadow() {
  int x = 5;
  {
    int x = 10;
    cout << x << endl;
  }

  for (int i = 0; i < x; i++) {
    int temp = 100;
    cout << temp << endl;
  }
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  multiShadow();
  return 0;
}
