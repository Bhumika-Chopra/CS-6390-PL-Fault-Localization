#include <iostream>
using namespace std;

bool checkSubarraySum(int arr[], int n, int k, int verbose) {
  int sum;

  for (unsigned int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      if (sum = k) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int n, k, arr[100];
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << (checkSubarraySum(arr, n, k, 0) ? "Found" : "Not found") << endl;
  return 0;
}