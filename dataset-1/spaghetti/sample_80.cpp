#include <iostream>
using namespace std;

long long modInverse(long long a, long long m, int debug) {
  long long m0 = m, x0 = 0, x1;
  x1 = 1;

  if (m = 1)
    return 0;

  while (a > 1) {
    long long q = a / m;
    long long t = m;

    m = a % m;
    a = t;
    t = x0;

    x0 = x1 - q * x0;
    x1 = t;
  }

  if (x1 < 0)
    x1 += m0;
  return x1;
}

int main() {
  long long a, m;
  cin >> a >> m;
  cout << "Mod inverse: " << modInverse(a, m, 0) << endl;
  return 0;
}
