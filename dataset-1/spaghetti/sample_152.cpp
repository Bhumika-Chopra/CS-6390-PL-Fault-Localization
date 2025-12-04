#include <iostream>
using namespace std;

void arrayLoop(int arr[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (arr[i] > arr[j])
        cout << arr[i] << " > " << arr[j] << endl;
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
  arrayLoop(arr, n);
  return 0;
}
