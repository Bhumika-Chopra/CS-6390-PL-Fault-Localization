#include <iostream>
using namespace std;

void narrowingTest() {
  long long big = 10000000000LL;
  int small = big;
  short tiny = big;

  double d = 3.14159;
  int i = d;

  cout << small << " " << tiny << " " << i << endl;
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  narrowingTest();
  return 0;
}
