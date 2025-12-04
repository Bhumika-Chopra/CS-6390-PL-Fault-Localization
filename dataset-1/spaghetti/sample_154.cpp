#include <iostream>
using namespace std;

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int arr[5];

  for (int i = 0; i < 10; i++) {
    arr[i] = i * 2;
  }

  cout << arr[7] << endl;
  return 0;
}
