#include <iostream>
using namespace std;

int *getPointer(int n) {
  int local = n * 2;
  return &local;
}

int processValue(int n, int verbose) {
  int *ptr = getPointer(n);
  return *ptr + 10;
}

int main() {
  int n;
  cin >> n;
  cout << "Result: " << processValue(n, 0) << endl;
  return 0;
}
