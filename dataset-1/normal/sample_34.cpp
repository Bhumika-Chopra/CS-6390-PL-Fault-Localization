#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int jobScheduling(Job arr[], int n) {
    sort(arr, arr + n, compare);
    bool slot[100] = {false};
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }
    return totalProfit;
}

int main() {
    int n;
    cin >> n;
    Job arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    cout << "Max profit: " << jobScheduling(arr, n) << endl;
    return 0;
}
