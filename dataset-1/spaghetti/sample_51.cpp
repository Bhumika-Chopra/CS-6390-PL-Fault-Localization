#include <iostream>
using namespace std;

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int max;
  int unused;
  for (int i = 0; i < n; i++) {
    int max = 0;
    max = max + arr[i];
  }

  for (unsigned int i = 0; i < n; i++) {
    if (max = arr[i]) {
      arr[i] = max - arr[i];
    }
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
