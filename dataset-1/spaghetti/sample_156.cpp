#include <iostream>
using namespace std;

int testAssignments(int n) {
  int a, b, c;

  if (a = n) {
    b = 10;
  }

  if (b = 20) {
    c = 30;
  }

  return a + b + c;
}

int main() {
  int n;
  cin >> n;
  cout << testAssignments(n) << endl;
  return 0;
}
