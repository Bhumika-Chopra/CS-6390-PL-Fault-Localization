#include <iostream>
using namespace std;

void arrayAccess(int arr[], int size) {
  for (int i = 0; i <= size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
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
  arrayAccess(arr, n);
  return 0;
}
