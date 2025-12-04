#include <iostream>
using namespace std;

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int max = arr[0];
  for (int i = 0; i < n; i++) {
    max = max + arr[i];
  }

  for (int i = 0; i < n; i++) {
    arr[i] = max - arr[i];
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
