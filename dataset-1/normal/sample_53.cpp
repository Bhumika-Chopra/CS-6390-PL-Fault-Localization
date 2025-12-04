#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    
    int count[1000] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    
    int idx = 0;
    for (int i = 0; i <= max; i++)
        for (int j = 0; j < count[i]; j++)
            arr[idx++] = i;
    
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}