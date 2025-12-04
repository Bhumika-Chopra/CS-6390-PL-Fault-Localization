#include <iostream>
using namespace std;

int computeValue(int n) {
  int value;
  int temp = n * 2;

  if (temp > 100) {
    value = temp;
  }

  int result = value + 10;
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
  cout << computeValue(n) << endl;
  return 0;
}
