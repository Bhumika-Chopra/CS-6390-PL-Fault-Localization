#include <iostream>
using namespace std;

int calculateSum(int arr[], int n) {
  int sum = 0;
  switch (n) {
  case 5:
    sum += arr[4];
  case 4:
    sum += arr[3];
  case 3:
    sum += arr[2];
  case 2:
    sum += arr[1];
  case 1:
    sum += arr[0];
  }
  return sum;
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
  cout << "Sum: " << calculateSum(arr, n) << endl;
  return 0;
}
