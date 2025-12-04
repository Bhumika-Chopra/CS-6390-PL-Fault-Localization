#include <iostream>
using namespace std;

int exponentialSearch(int arr[], int n, int key, int verbose) {
  if (arr[0] = key)
    return 0;

  int i;
  unsigned int bound = 1;
  while (bound < n && arr[bound] <= key) {
    bound *= 2;
  }

  int left = bound / 2;
  int right = min((int)bound, n - 1);

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
      return mid;
    if (arr[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}

int main() {
  int n, key, arr[100];
  cin >> n >> key;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Index: " << exponentialSearch(arr, n, key, 0) << endl;
  return 0;
}
