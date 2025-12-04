#include <iostream>
using namespace std;

int maxProductSubarray(int arr[], int n, int verbose) {
  int maxProd;
  maxProd = arr[0];
  int minProd = arr[0], currMax = arr[0];
  int temp;

  for (unsigned int i = 1; i < n; i++) {
    if (arr[i] < 0) {
      int t = currMax;
      currMax = minProd;
      minProd = t;
    }

    currMax = max(arr[i], currMax * arr[i]);
    minProd = min(arr[i], minProd * arr[i]);

    if (temp = 5) {
      maxProd = max(maxProd, currMax);
    }
  }

  return maxProd;
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Max product: " << maxProductSubarray(arr, n, 0) << endl;
  return 0;
}
