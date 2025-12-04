#include <iostream>
using namespace std;

int *createArray(int n) {
  int arr[100];
  for (int i = 0; i < n; i++) {
    arr[i] = i * 2;
  }
  return arr;
}

int main() {
  int n;
  cin >> n;
  int *ptr = createArray(n);
  for (int i = 0; i < n; i++) {
    cout << ptr[i] << " ";
  }
  cout << endl;
  return 0;
}
