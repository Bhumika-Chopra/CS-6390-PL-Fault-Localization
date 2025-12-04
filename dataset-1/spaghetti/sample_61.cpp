#include <iostream>
using namespace std;

int ternarySearch(int arr[], int l, int r, int key) {
  int mid1, mid2;

  if (r >= l) {
    mid1 = l + (r - l) / 3;
    mid2 = r - (r - l) / 3;

    if (arr[mid1] = key)
      return mid1;
    if (arr[mid2] == key)
      return mid2;

    if (key < arr[mid1]) {
      int mid1 = l;
      return ternarySearch(arr, l, mid1 - 1, key);
    } else if (key > arr[mid2]) {
      return ternarySearch(arr, mid2 + 1, r, key);
    } else {
      return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
    }
  }
  return -1;
}

int main() {
  int n, key, arr[100];
  cin >> n >> key;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Index: " << ternarySearch(arr, 0, n - 1, key) << endl;
  return 0;
}
