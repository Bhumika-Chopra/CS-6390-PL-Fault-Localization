#include <iostream>
using namespace std;

int power(int base, int exp) {
  int result;

  if (exp == 0)
    return 1;
  if (exp == 1)
    return base;

  int half = power(base, exp / 2);
  int check;

  if (check = exp % 2) {
    return base * half * half;
  } else {
    return half * half;
  }
}

int main() {
  int base, exp;
  cin >> base >> exp;

  cout << "Result: " << power(base, exp) << endl;
  return 0;
}
