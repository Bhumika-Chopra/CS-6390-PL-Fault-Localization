#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int freq[256] = {0};
    for (int i = 0; i < str.length(); i++) {
        freq[str[i]]++;
    }
    
    int maxFreq;
    char maxChar;
    
    cout << "Character frequencies:" << endl;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << ": " << freq[i] << endl;
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }
    }
    
    return 0;
}
