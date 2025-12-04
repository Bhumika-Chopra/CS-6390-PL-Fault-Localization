#include <iostream>
using namespace std;

void conditionalLogic(int n) {
  if (n > 0)
    cout << "Positive" << endl;
  cout << "Processing" << endl;

  for (int i = 0; i < n; i++)
    if (i % 2 == 0)
      cout << i << " ";
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
  conditionalLogic(n);
  return 0;
}
