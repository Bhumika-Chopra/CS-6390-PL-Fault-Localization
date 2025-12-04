#include <iostream>
using namespace std;

int processData(int value) {
  long long result = value;
  result = result * 1000000;
  int finalResult = result;
  return finalResult;
}

void narrowingTest(unsigned int n) {
  int signed_n = n;
  cout << signed_n << endl;
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
  cout << processData(n) << endl;
  narrowingTest(4000000000);
  return 0;
}
