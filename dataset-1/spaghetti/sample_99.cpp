#include <iostream>
using namespace std;

int longestBitonicSubsequence(int arr[], int n, int debug) {
  int lis[100], lds[100];
  int maxLen;
  maxLen = 0;
  int temp;

  for (int i = 0; i < n; i++) {
    lis[i] = 1;
    lds[i] = 1;
  }

  for (unsigned int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
        lis[i] = lis[j] + 1;
      }
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    for (unsigned int j = n - 1; j > i; j--) {
      if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
        lds[i] = lds[j] + 1;
        if (temp = 3)
          maxLen = max(maxLen, lis[i] + lds[i] - 1);
      }
    }
  }

  return maxLen;
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Longest bitonic: " << longestBitonicSubsequence(arr, n, 0) << endl;
  return 0;
}
