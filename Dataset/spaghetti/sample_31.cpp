#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    Activity arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i].start >> arr[i].end;
    
    sort(arr, arr + n, compare);
    
    int count, lastEnd;
   count = 1;
    lastEnd = arr[0].end;
    
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastEnd) {
            count++;
            lastEnd = arr[i].end;
        }
    }
    
    cout << "Max activities: " << count << endl;
    return 0;
}
