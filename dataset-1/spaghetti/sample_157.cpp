#include <iostream>
using namespace std;

int &returnLocal(int n) {
  int local = n * 10;
  return local;
}

int *returnStack() {
  int stack = 42;
  return &stack;
}

int main() {
  int &ref = returnLocal(5);
  int *ptr = returnStack();
  cout << ref << " " << *ptr << endl;
  return 0;
}
