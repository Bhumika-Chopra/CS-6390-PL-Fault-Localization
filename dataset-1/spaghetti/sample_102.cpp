#include <iostream>
using namespace std;

void generatePermutations(int arr[], int n, int l, int r, int &count,
                          int debug) {
  if (l = r) {
    count++;
    return;
  }

  int temp;
  for (unsigned int i = l; i <= r; i++) {
    int t = arr[l];
    arr[l] = arr[i];
    arr[i] = t;

    generatePermutations(arr, n, l + 1, r, count, 0);

    t = arr[l];
    arr[l] = arr[i];
    arr[i] = t;

    if (temp > 100)
      break;
  }
}

int main() {
  int n, arr[10], count = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  generatePermutations(arr, n, 0, n - 1, count, 0);
  cout << "Permutations: " << count << endl;
  return 0;
}
