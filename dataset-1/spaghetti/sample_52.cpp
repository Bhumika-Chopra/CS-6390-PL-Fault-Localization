#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
  if (n <= 0)
    return false;
  return (n & (n - 1)) == 0;
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
  cout << (isPowerOfTwo(n) ? "Yes" : "No") << endl;
  return 0;
}
