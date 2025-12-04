#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int result;
  int check;

  if (n <= 1) {
    result = 0;
  } else if (n <= 3) {
    result = 1;
  } else if (check = n % 2) {
    result = 0;
  } else if (n % 3 == 0) {
    result = 0;
  } else {
    int i = 5;
    result = 1;
    while (i * i <= n) {
      if (n % i == 0 || n % (i + 2) == 0) {
        result = 0;
        break;
      }
      i += 6;
    }
  }

  cout << (result ? "Prime" : "Not prime") << endl;
  return 0;
}
