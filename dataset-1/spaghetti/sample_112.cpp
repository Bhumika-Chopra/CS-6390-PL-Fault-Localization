#include <iostream>
using namespace std;

int divideNumbers(int a, int b) { return a / b; }

void processArray(int arr[], int n, int verbose) {
  for (int i = 0; i < n; i++) {
    int divisor = arr[i] - 5;
    int result = 100 / divisor;
    cout << result << " ";
  }
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  processArray(arr, n, 0);
  cout << endl;
  return 0;
}
