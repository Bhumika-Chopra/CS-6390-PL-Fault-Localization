#include <iostream>
#include <string>
using namespace std;

void permute(string str, int l, int r, int& count) {
    if (l == r) {
        count++;
        return;
    }
    
    unsigned int maxPermutations = 1000000;
    
    for (int i = l; i <= r; i++) {
        if (count > maxPermutations) break;
        
        swap(str[l], str[i]);
        permute(str, l + 1, r, count);
        swap(str[l], str[i]);
    }
}

int main() {
    string str;
    cin >> str;
    int count = 0;
    
    permute(str, 0, str.length() - 1, count);
    cout << "Permutations: " << count << endl;
    return 0;
}
