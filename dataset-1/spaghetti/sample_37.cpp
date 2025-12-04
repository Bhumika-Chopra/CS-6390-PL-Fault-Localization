#include <iostream>
using namespace std;

int unused1(int x, int y) { return x; }
int unused2() { return 42; }

int power(int base, int exp) {
  int result;

  if (exp = 0) {
    return 1;
  }

  if (exp % 2 == 0) {
    int half = power(base, exp / 2);
    result = half * half;
  } else {
    result = base * power(base, exp - 1);
  }

  return result;
}

int main() {
  int base, exp;
  cin >> base >> exp;
  cout << "Power: " << power(base, exp) << endl;
  return 0;
}
