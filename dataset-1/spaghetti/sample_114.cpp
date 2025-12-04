#include <iostream>
using namespace std;

int helperFunc1(int x) { return x * 2; }

int helperFunc2(int x) { return x + 5; }

int computeValue(int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result += i;
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
  cout << "Result: " << computeValue(n) << endl;
  return 0;
}
