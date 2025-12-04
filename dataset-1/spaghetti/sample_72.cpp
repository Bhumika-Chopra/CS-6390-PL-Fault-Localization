#include <iostream>
using namespace std;

void primeFactors(int n) {
  while (n % 2 == 0) {
    cout << 2 << " ";
    n /= 2;
  }

  for (int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      cout << i << " ";
      n /= i;
    }
  }

  if (n > 2)
    cout << n << " ";
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
  primeFactors(n);
  return 0;
}
