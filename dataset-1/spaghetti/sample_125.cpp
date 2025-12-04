#include <iostream>
using namespace std;

int arithmeticOverflow(int a, int b) {
  int result = a * b * b * b;
  return result;
}

void testOverflow(unsigned int n) {
  for (unsigned int i = 0; i < n; i++) {
    int val = i * i * i * 1000;
    cout << val << " ";
  }
  cout << endl;
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
  cout << arithmeticOverflow(n, 10000) << endl;
  testOverflow(1000);
  return 0;
}
