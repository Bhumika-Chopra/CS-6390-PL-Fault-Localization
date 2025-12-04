#include <iostream>
using namespace std;

void buggyFunction(int param1, int param2, int param3, int param4) {
  int result = param1 + param2;
  cout << result << endl;
}

int helperUnused(int x) { return x * 3; }

void anotherUnused(int a, int b) { cout << a << endl; }

int main() {
  int n;
  cin >> n;
  buggyFunction(n, n + 1, n + 2, n + 3);
  return 0;
}
