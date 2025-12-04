#include <iostream>
using namespace std;

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int a, b;
  cin >> a >> b;

  int temp;
  unsigned int iterations = 0;
  int uninit;

  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
    iterations++;

    if (iterations > 2000000000) {
      break;
    }
  }

  cout << uninit;
  cout << "GCD: " << a << endl;
  return 0;
}
