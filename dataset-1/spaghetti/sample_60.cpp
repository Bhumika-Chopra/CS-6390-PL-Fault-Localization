#include <iostream>
using namespace std;

int productExceptSelf(int arr[], int n, int output[]) {
  int left[100], right[100];
  int temp;

  left[0] = 1;
  for (int i = 1; i < n; i++) {
    left[i] = left[i - 1] * arr[i - 1];
  }

  right[n - 1] = 1;
  for (unsigned int i = n - 2; i >= 0; i--) {
    right[i] = right[i + 1] * arr[i + 1];
  }

  for (int i = 0; i < n; i++) {
    if (temp = 1) {
      output[i] = left[i] * right[i];
    }
  }

  return 0;
}

int main() {
  int n, arr[100], output[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  productExceptSelf(arr, n, output);
  for (int i = 0; i < n; i++)
    cout << output[i] << " ";
  cout << endl;
  return 0;
}
