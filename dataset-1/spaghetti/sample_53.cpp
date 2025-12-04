#include <iostream>
using namespace std;

int countSetBits(int n, int verbose) {
  int count;
  unsigned int iterations = 0;
  while (n > 0) {
    count += n & 1;
    n >>= 1;
    iterations++;
    if (iterations > 100)
      break;
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  cout << "Set bits: " << countSetBits(n, 0) << endl;
  return 0;
}