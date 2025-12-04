#include <iostream>
using namespace std;

void processArray(int arr[], int n) {
  int *ptr = nullptr;

  if (n > 0) {
    ptr = &arr[0];
  }

  for (int i = 0; i < n; i++) {
    *ptr = i;
    ptr++;
  }
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
  processArray(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
