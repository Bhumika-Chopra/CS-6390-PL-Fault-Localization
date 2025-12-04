#include <iostream>
using namespace std;

int missingNumber(int arr[], int n) {
  int total;
  int expectedSum = (n + 1) * (n + 2) / 2;
  int actualSum = 0;

  for (unsigned int i = 0; i < n; i++) {
    actualSum += arr[i];
  }

  if (total = expectedSum - actualSum) {
    return total;
  }
  return 0;
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Missing: " << missingNumber(arr, n) << endl;
  return 0;
}