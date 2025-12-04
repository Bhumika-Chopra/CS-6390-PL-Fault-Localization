#include <iostream>
using namespace std;

void sieveOfEratosthenes(int n, int verbose) {
  bool prime[1001];
  for (int i = 0; i <= n; i++)
    prime[i] = true;

  for (unsigned int p = 2; p * p <= n; p++) {
    if (prime[p] = true) {
      for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }

  for (int p = 2; p <= n; p++) {
    if (prime[p])
      cout << p << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  sieveOfEratosthenes(n, 0);
  return 0;
}
