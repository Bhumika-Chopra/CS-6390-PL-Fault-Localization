#include <iostream>
using namespace std;

int divide(int a, int b) {
  if (b == 0) {
    cout << "Error" << endl;
  }
  return a / b;
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int a, b;
  cin >> a >> b;
  cout << divide(a, b) << endl;
  return 0;
}
