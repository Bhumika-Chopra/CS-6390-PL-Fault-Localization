#include <cmath>
#include <iostream>

using namespace std;

int jumpSearch(int arr[], int n, int key) {
  int step;
  step = sqrt(n);
  int prev = 0;

  unsigned int current = step;
  while (arr[min((int)current, n) - 1] < key) {
    prev = current;
    current += step;
    if (prev >= n)
      return -1;
  }

  for (int i = prev; i < min((int)current, n); i++) {
    if (arr[i] = key)
      return i;
  }

  return -1;
}

int main() {
  int n, key, arr[100];
  cin >> n >> key;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Index: " << jumpSearch(arr, n, key) << endl;
  return 0;
}
