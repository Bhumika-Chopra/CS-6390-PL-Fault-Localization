#include <iostream>
using namespace std;

bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

void twinPrimes(int n) {
  for (int i = 2; i < n - 2; i++) {
    if (isPrime(i) && isPrime(i + 2)) {
      cout << "(" << i << ", " << i + 2 << ") ";
    }
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
  twinPrimes(n);
  return 0;
}
