#include <iostream>
using namespace std;

int unusedHelper1(int x) { return x * 2; }
int unusedHelper2(int x) { return x + 5; }
int unusedHelper3(int x) { return x - 3; }

void processValue(int n, int debug, int verbose, int mode) {
  int result = n * 3;
  cout << result << endl;
}

int main() {
  int n;
  cin >> n;
  processValue(n, 0, 0, 0);
  return 0;
}
