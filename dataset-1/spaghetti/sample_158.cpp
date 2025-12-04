#include <iostream>
using namespace std;

void typeMix() {
  long long ll = 99999999999LL;
  int i = ll;

  unsigned int ui = 4000000000U;
  int si = ui;

  double d = 123.456;
  int di = d;

  cout << i << " " << si << " " << di << endl;
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  typeMix();
  return 0;
}
