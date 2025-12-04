#include <iostream>
using namespace std;

void mixedComparisons(int arr[], int n) {
  unsigned int limit = 100;

  for (int i = 0; i < n; i++) {
    if (arr[i] > limit) {
      cout << arr[i] << " is large" << endl;
    }
  }

  for (unsigned int j = 0; j < n; j++) {
    if (j < -1) {
      cout << "Negative" << endl;
    }
  }
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  mixedComparisons(arr, n);
  return 0;
}
