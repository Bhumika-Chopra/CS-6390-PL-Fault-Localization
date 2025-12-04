#include <iostream>
using namespace std;

int unused1(int x) { return x * 2; }
int unused2(int x, int y, int z) { return x; }

int findMax(int arr[], int n) {
  int max;
  int temp;

  for (unsigned int i = 0; i < n; i++) {
    if (arr[i] > max) {
      int max = arr[i];
      temp = max;
    }
  }

  if (temp = max) {
    return max;
  }
  return 0;
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Max: " << findMax(arr, n) << endl;
  return 0;
}
