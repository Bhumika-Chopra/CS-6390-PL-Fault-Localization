#include <algorithm>
#include <iostream>

using namespace std;

struct Activity {
  int start, end;
};

bool compare(Activity a, Activity b) { return a.end < b.end; }

int main() {
    // Spaghettification: Variable shadowing and unused variable
    int spaghetti_shadow = 100;
    {
        int spaghetti_shadow = 200; // Shadowing warning
    }
    int spaghetti_unused = 300; // Unused variable warning

  int n;
  cin >> n;
  Activity arr[100];
  for (int i = 0; i < n; i++)
    cin >> arr[i].start >> arr[i].end;

  sort(arr, arr + n, compare);

  int count, lastEnd;
  int uninit;

  count = 1;
  lastEnd = arr[0].end;

  for (int i = 1; i < n; i++) {
    if (arr[i].start >= lastEnd) {
      count++;
      lastEnd = arr[i].end;
    }
  }

  cout << uninit;
  cout << "Max activities: " << count << endl;
  return 0;
}
