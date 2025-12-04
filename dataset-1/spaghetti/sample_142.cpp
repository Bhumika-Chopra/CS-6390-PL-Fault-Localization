#include <iostream>
using namespace std;

void testOverflow() {
  int a = 2147483647;
  int b = a + 1;
  cout << b << endl;

  unsigned int c = 4294967295U;
  unsigned int d = c + 1;
  cout << d << endl;
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  testOverflow();
  return 0;
}
