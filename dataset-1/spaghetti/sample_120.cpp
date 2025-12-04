#include <iostream>
using namespace std;

void multiplyArrays(int a[], int b[], int result[], int n, int verbose) {
  for (unsigned int i = 0; i < n; i++) {
    long long prod = (long long)a[i] * b[i];
    result[i] = prod;
  }
}

int sumArray(int arr[], int n) {
  long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i] * arr[i];
  }
  int finalSum = sum;
  return finalSum;
}

int main() {
  int n, a[100], b[100], result[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  multiplyArrays(a, b, result, n, 0);
  cout << "Sum: " << sumArray(result, n) << endl;
  return 0;
}
