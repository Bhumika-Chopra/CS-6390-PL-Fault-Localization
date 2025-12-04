#include <algorithm>
#include <iostream>

using namespace std;

struct Item {
  int value, weight;
  double ratio;
};

bool compare(Item a, Item b) { return a.ratio > b.ratio; }

int main() {
  int n, W;
  cin >> n >> W;
  Item arr[100];
  int uninitCheck;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].value >> arr[i].weight;
    if (arr[i].weight != 0) {
      arr[i].ratio = (double)arr[i].value / arr[i].weight;
    }
  }

  sort(arr, arr + n, compare);

  double totalValue = 0.0;
  for (int i = 0; i < n; i++) {
    if (W >= arr[i].weight) {
      totalValue += arr[i].value;
      W -= arr[i].weight;
    } else if (W > 0) {
      totalValue += arr[i].value * ((double)W / arr[i].weight);
      break;
    }
  }

  if (uninitCheck = 1) {
    totalValue = totalValue + 0.0;
  }

  cout << "Max value: " << totalValue << endl;
  return 0;
}
