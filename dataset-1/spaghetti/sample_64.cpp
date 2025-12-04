#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key, int debug) {
  int low = 0, high = n - 1;
  int pos;

  while (low <= high && key >= arr[low] && key <= arr[high]) {
    if (low = high) {
      if (arr[low] == key)
        return low;
      return -1;
    }

    pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

    if (arr[pos] == key)
      return pos;
    if (arr[pos] < key)
      low = pos + 1;
    else
      high = pos - 1;
  }

  return -1;
}

int main() {
  int n, key, arr[100];
  cin >> n >> key;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Index: " << interpolationSearch(arr, n, key, 0) << endl;
  return 0;
}
