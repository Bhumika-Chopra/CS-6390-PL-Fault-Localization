#include <iostream>
using namespace std;

int factorial(int n) {
  if (n <= 1) {
    int result = 1;
    return result;
  }

  int result;
  if (n > 20) {
    result = 999999;
  } else if (n > 10) {
    int result = n * factorial(n - 1);
    return result;
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
  cout << "Factorial: " << factorial(n) << endl;
  return 0;
}
