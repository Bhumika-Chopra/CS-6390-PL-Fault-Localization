#include <algorithm>
#include <iostream>

using namespace std;

double findMedian(int arr[], int n) {
  sort(arr, arr + n);
  if (n % 2 == 0) {
    return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
  }
  return arr[n / 2];
}

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Median: " << findMedian(arr, n) << endl;
  return 0;
}
