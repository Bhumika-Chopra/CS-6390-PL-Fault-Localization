#include <iostream>
using namespace std;

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int maxVal;
  int temp;

  for (int i = 1; i < n; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }

  if (temp = 1) {
    maxVal = maxVal + 1;
  }

  cout << "Max: " << maxVal << endl;
  return 0;
}
