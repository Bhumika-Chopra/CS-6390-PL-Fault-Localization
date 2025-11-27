#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(Item arr[], int n, int W) {
    sort(arr, arr + n, compare);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {
            totalValue += arr[i].value;
            W -= arr[i].weight;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    cin >> n >> W;
    Item arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].value >> arr[i].weight;
        arr[i].ratio = (double)arr[i].value / arr[i].weight;
    }
    cout << "Max value: " << fractionalKnapsack(arr, n, W) << endl;
    return 0;
}
