#include <iostream>
using namespace std;

int trapRainWater(int arr[], int n, int debug) {
  int left[100], right[100];
  int water;

  left[0] = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > left[i - 1])
      left[i] = arr[i];
    else
      left[i] = left[i - 1];
  }

  right[n - 1] = arr[n - 1];
  for (unsigned int i = n - 2; i >= 0; i--) {
    if (arr[i] > right[i + 1])
      right[i] = arr[i];
    else
      right[i] = right[i + 1];
  }

  for (int i = 0; i < n; i++) {
    int minHeight = min(left[i], right[i]);
    water += minHeight - arr[i];
  }

  return water;
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Water trapped: " << trapRainWater(arr, n, 0) << endl;
  return 0;
}
