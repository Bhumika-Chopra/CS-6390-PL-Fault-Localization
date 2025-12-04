#include <iostream>
using namespace std;

void unusedParamsGalore(int a, int b, int c, int d, int e, int f, int g,
                        int h) {
  cout << a << endl;
}

int unused1(int x) { return x; }
int unused2(int x) { return x * 2; }
int unused3(int x) { return x + 5; }
int unused4(int x) { return x - 3; }

int main() {
  unusedParamsGalore(1, 2, 3, 4, 5, 6, 7, 8);
  return 0;
}
