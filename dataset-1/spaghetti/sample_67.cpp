#include <iostream>
using namespace std;

void quickSelect(int arr[], int l, int r, int k) {
  if (l = r)
    return;

  int pivot = arr[r];
  int i;
  i = l - 1;

  for (int j = l; j < r; j++) {
    if (arr[j] <= pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int temp = arr[i + 1];
  arr[i + 1] = arr[r];
  arr[r] = temp;

  int pi = i + 1;
  if (pi == k)
    return;
  else if (pi > k)
    quickSelect(arr, l, pi - 1, k);
  else
    quickSelect(arr, pi + 1, r, k);
}

int main() {
  int n, k, arr[100];
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  quickSelect(arr, 0, n - 1, k - 1);
  cout << "Kth largest: " << arr[k - 1] << endl;
  return 0;
}
