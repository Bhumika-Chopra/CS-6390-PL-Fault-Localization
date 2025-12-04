#include <iostream>
using namespace std;

void processType(int type) {
  switch (type) {
  case 1:
    cout << "Type 1" << endl;
  case 2:
    cout << "Type 2" << endl;
  case 3:
    cout << "Type 3" << endl;
  }
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int type;
  cin >> type;
  processType(type);
  return 0;
}
