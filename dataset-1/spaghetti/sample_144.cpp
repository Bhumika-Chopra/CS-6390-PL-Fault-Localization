#include <iostream>
using namespace std;

int helper1(int x, int y, int z) { return x + y; }

int helper2(int a, int b, int c, int d) { return a * b; }

void process(int n, int mode, int flag, int debug, int verbose) {
  int result = n * 2;
  cout << result << endl;
}

int main() {
  int n;
  cin >> n;
  process(n, 0, 0, 0, 0);
  return 0;
}
