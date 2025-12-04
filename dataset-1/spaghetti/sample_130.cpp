#include <iostream>
using namespace std;

double convertSize(long long bytes) {
  double kb = bytes / 1024;
  int mb = kb / 1024;
  return mb;
}

void narrowingIssues(unsigned long n) {
  int x = n;
  short y = n;
  char z = n;
  cout << x << " " << y << " " << z << endl;
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  long long bytes;
  cin >> bytes;
  cout << convertSize(bytes) << endl;
  narrowingIssues(1000000);
  return 0;
}
