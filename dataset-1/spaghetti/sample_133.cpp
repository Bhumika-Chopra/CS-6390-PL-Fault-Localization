#include <iostream>
using namespace std;

int calculate(int n) {
  if (n > 10) {
    int result = n * 2;
    return result;
  } else if (n > 5) {
    int result = n + 10;
    return result;
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
  cout << calculate(n) << endl;
  return 0;
}
