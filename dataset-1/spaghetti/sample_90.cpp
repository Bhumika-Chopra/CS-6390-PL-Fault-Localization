#include <iostream>
using namespace std;

bool partitionProblem(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];

  if (sum % 2 == 1)
    return false;

  bool dp[1001] = {0};
  dp[0] = true;

  for (int i = 0; i < n; i++) {
    for (int j = sum / 2; j >= arr[i]; j--) {
      dp[j] = dp[j] || dp[j - arr[i]];
    }
  }

  return dp[sum / 2];
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
  cout << (partitionProblem(arr, n) ? "Possible" : "Not possible") << endl;
  return 0;
}
