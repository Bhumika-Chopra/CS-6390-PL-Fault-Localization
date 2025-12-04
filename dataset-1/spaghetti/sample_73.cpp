#include <iostream>
using namespace std;

long long modPower(long long base, long long exp, long long mod) {
  long long result = 1;
  base = base % mod;

  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    exp = exp >> 1;
    base = (base * base) % mod;
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

  long long base, exp, mod;
  cin >> base >> exp >> mod;
  cout << "Result: " << modPower(base, exp, mod) << endl;
  return 0;
}
