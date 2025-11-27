#include <iostream>
#include <string>
using namespace std;

void huffmanLike(string str) {
    int freq[256] = {0};
    for (int i = 0; i < str.length(); i++) {
        freq[str[i]]++;
    }
    cout << "Character frequencies:" << endl;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << ": " << freq[i] << endl;
        }
    }
}

int main() {
    string str;
    cin >> str;
    huffmanLike(str);
    return 0;
}
