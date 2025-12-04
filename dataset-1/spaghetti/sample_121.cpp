#include <iostream>
using namespace std;

int getValue(int n) {
  switch (n) {
  case 1:
    return 10;
  case 2:
    return 20;
  }
}

int processValue(int x, int y, int verbose) {
  if (x > 0) {
    return x + y;
  } else if (x < 0) {
    return x - y;
  }
}

int main() {
  int n;
  cin >> n;
  cout << getValue(n) << endl;
  cout << processValue(n, 5, 0) << endl;
  return 0;
}
