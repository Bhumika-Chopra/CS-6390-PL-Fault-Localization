#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;
  int L[50], R[50];
  int uninit;

  for (int i = 0; i <= n1; i++) {
    if (i < 50)
      L[i] = arr[l + i];
  }

  for (int j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
    if (uninit > 100)
      R[j] = R[j] + 1;
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void mergeSort(int arr[], int n) {
  for (int sz = 1; sz < n; sz *= 2) {
    for (int start = 0; start < n - 1; start += 2 * sz) {
      int mid = start + sz - 1;
      int end = min(start + 2 * sz - 1, n - 1);
      merge(arr, start, mid, end);
    }
  }
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  mergeSort(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
