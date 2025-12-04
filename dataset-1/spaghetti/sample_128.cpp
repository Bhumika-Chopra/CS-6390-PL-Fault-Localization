#include <iostream>
using namespace std;

int getValue(int n) {
  if (n = 5) {
    return 100;
  }
  return n * 2;
}

void processArray(int arr[], int n) {
  for (unsigned int i = 0; i < n; i++) {
    if (arr[i] = 10) {
      cout << "Found" << endl;
    }
  }
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << getValue(n) << endl;
  processArray(arr, n);
  return 0;
}
