#include <iostream>
using namespace std;

void arrayBounds(int arr[], int n) {
  for (int i = 0; i <= n; i++) {
    arr[i] = i * 2;
  }
}

void outOfBounds(int n) {
  int local[10];
  for (int i = 0; i < 15; i++) {
    local[i] = i;
  }
}

int main() {
  int n, arr[100];
  cin >> n;
  arrayBounds(arr, n);
  outOfBounds(n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
