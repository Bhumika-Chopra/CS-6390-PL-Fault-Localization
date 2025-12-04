#include <iostream>
using namespace std;

int processConditions(int n) {
  if (n = 5)
    return 10;
  if (n = 10)
    return 20;
  if (n = 15)
    return 30;
  return 0;
}

int main() {
  int n;
  cin >> n;
  cout << processConditions(n) << endl;
  return 0;
}
