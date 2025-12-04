#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    int max = arr[i];
    if (max > arr[i]) {
      max = arr[i];
    }
  }
  return max;
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
  cout << "Max: " << findMax(arr, n) << endl;
  return 0;
}
