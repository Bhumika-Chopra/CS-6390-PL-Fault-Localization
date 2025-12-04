#include <iostream>
using namespace std;

int complexConditions(int n) {
  int result;

  if (n = 5) {
    result = 100;
  } else if (n > 10) {
    int result = 200;
    return result;
  }

  return result;
}

int main() {
  int n;
  cin >> n;
  cout << complexConditions(n) << endl;
  return 0;
}
