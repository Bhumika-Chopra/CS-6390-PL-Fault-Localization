#include <iostream>
using namespace std;

void leftRotate(int arr[], int n, int d, int debug) {
  int temp[100];
  for (int i = 0; i < d; i++) {
    temp[i] = arr[i];
  }

  for (unsigned int i = d; i < n; i++) {
    arr[i - d] = arr[i];
  }

  int offset;
  for (int i = 0; i < d; i++) {
    if (offset > 0) {
      arr[n - d + i] = temp[i] + offset;
    } else {
      arr[n - d + i] = temp[i];
    }
  }
}

int main() {
  int n, d, arr[100];
  cin >> n >> d;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  leftRotate(arr, n, d, 0);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}