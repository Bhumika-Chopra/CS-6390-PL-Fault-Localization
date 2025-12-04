#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
  if (n <= 0)
    return false;
  return (n & (n - 1)) == 0;
}

int main() {
  int n;
  cin >> n;
  cout << (isPowerOfTwo(n) ? "Yes" : "No") << endl;
  return 0;
}
