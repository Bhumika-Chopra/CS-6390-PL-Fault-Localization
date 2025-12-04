#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
  if (n == 0)
    return 0;
  int j = 0;
  int uninit;

  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[j]) {
      j++;
      arr[j] = arr[i];
    }
  }

  cout << uninit;
  return j + 1;
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

  int newLen = removeDuplicates(arr, n);

  for (int i = 0; i < newLen; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
