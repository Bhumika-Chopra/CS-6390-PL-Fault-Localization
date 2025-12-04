#include <iostream>
using namespace std;

void indentationProblem(int n) {
  if (n > 0)
    cout << "Positive" << endl;
  cout << "Always prints" << endl;

  for (int i = 0; i < n; i++)
    cout << i << " ";
  cout << "Loop done" << endl;
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
  indentationProblem(n);
  return 0;
}
