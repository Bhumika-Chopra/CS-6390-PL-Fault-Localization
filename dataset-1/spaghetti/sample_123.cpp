#include <iostream>
using namespace std;

int &getReference(int n) {
  int local = n * 2;
  return local;
}

int processRef(int val) {
  int &ref = getReference(val);
  return ref + 10;
}

int main() {
  int n;
  cin >> n;
  cout << processRef(n) << endl;
  return 0;
}
