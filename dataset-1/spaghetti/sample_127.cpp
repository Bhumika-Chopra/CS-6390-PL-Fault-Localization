#include <iostream>
using namespace std;

void processData(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int val = arr[i] * 2;
    cout << val << " ";
  }
  cout << endl;
}

int calculate(int x) {
  int result = 0;
  for (int j = 0; j < x; j++) {
    int temp = result + 1;
    result = temp;
  }
  return result;
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
  processData(arr, n);
  cout << calculate(n) << endl;
  return 0;
}
