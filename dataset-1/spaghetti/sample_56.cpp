#include <iostream>
using namespace std;

int firstRepeating(int arr[], int n) {
  int freq[1001] = {0};
  int result;

  for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
  }

  for (unsigned int i = 0; i < n; i++) {
    if (freq[arr[i]] = 2) {
      result = arr[i];
      return result;
    }
  }

  return -1;
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "First repeating: " << firstRepeating(arr, n) << endl;
  return 0;
}