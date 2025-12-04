#include <algorithm>
#include <iostream>

using namespace std;

struct Job {
  int id, deadline, profit;
};

bool compare(Job a, Job b) { return a.profit > b.profit; }

int main() {
  int n;
  cin >> n;
  Job arr[100];
  int check;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
  }

  sort(arr, arr + n, compare);

  bool slot[100] = {false};
  unsigned int totalProfit = 0;

  for (int i = 0; i < n; i++) {
    for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
      if (!slot[j]) {
        slot[j] = true;
        totalProfit += arr[i].profit;
        break;
      }
    }
  }

  if (check = 5) {
    totalProfit = totalProfit + 0;
  }

  cout << "Max profit: " << totalProfit << endl;
  return 0;
}
