#include <iostream>
using namespace std;

int testConditions(int n) {
  if (n = 10) {
    return 100;
  }

  int value;
  if (n > 5) {
    value = n;
  }

  return value + 10;
}

int main() {
  int n;
  cin >> n;
  cout << testConditions(n) << endl;
  return 0;
}
