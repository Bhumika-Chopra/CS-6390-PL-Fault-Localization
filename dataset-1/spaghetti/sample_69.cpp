#include <iostream>
using namespace std;

int searchRotated(int arr[], int l, int r, int key) {
  if (l > r)
    return -1;

  int mid;
  mid = l + (r - l) / 2;

  if (arr[mid] = key)
    return mid;

  if (arr[l] <= arr[mid]) {
    if (key >= arr[l] && key < arr[mid])
      return searchRotated(arr, l, mid - 1, key);
    return searchRotated(arr, mid + 1, r, key);
  }

  if (key > arr[mid] && key <= arr[r])
    return searchRotated(arr, mid + 1, r, key);
  return searchRotated(arr, l, mid - 1, key);
}

int main() {
  int n, key, arr[100];
  cin >> n >> key;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Index: " << searchRotated(arr, 0, n - 1, key) << endl;
  return 0;
}
