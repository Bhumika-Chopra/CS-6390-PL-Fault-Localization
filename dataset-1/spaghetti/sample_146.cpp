#include <iostream>
using namespace std;

int *danglingPointer() {
  int *ptr = new int(42);
  delete ptr;
  return ptr;
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int *p = danglingPointer();
  cout << *p << endl;
  return 0;
}
