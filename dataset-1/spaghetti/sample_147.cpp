#include <iostream>
using namespace std;

void conversionIssues() {
  unsigned int u = 4000000000U;
  int s = u;

  long long big = 9999999999LL;
  int med = big;

  float f = 1.99f;
  int i = f;

  cout << s << " " << med << " " << i << endl;
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  conversionIssues();
  return 0;
}
