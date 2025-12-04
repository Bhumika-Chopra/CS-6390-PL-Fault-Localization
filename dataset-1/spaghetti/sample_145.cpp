#include <iostream>
using namespace std;

void nestedShadowing(int x) {
  {
    int y = x;
    {
      int y = x * 2;
      {
        int y = x * 3;
        cout << y << endl;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  nestedShadowing(n);
  return 0;
}
