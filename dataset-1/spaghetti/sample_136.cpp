#include <iostream>
using namespace std;

void shadowingIssues(int x) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      int i = j * 2;
      cout << i << " ";
    }
  }
  cout << endl;
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int n;
  cin >> n;
  shadowingIssues(n);
  return 0;
}
