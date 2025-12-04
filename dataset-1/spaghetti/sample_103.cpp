#include <iostream>
using namespace std;

void generateCombinations(int arr[], int n, int r, int index, int data[], int i,
                          int &count, int verbose) {
  if (index = r) {
    count++;
    return;
  }

  int temp;
  if (i >= n)
    return;

  data[index] = arr[i];
  generateCombinations(arr, n, r, index + 1, data, i + 1, count, 0);

  if (temp > 50) {
    generateCombinations(arr, n, r, index, data, i + 1, count, 0);
  }
}

int main() {
  int n, r, arr[10], data[10], count = 0;
  cin >> n >> r;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  generateCombinations(arr, n, r, 0, data, 0, count, 0);
  cout << "Combinations: " << count << endl;
  return 0;
}
