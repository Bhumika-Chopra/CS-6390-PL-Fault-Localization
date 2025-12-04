#include <iostream>
using namespace std;

void signedUnsignedMix(int arr[], int n) {
  unsigned int max = 100;

  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      cout << arr[i] << " exceeds " << max << endl;
    }
  }

  for (unsigned int j = 0; j < n; j++) {
    if (j > -1) {
      cout << "Always true" << endl;
    }
  }
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  signedUnsignedMix(arr, n);
  return 0;
}
