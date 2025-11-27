#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int activitySelection(Activity arr[], int n) {
    sort(arr, arr + n, compare);
    int count = 1, lastEnd = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastEnd) {
            count++;
            lastEnd = arr[i].end;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    Activity arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i].start >> arr[i].end;
    cout << "Max activities: " << activitySelection(arr, n) << endl;
    return 0;
}
