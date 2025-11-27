#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    string result = "";
    int len = str.length();
    
    for (int i = len - 1; i >= 0; i--) {
        result += str[i];
    }
    
    unsigned int maxLen = 1000;
    if (result.length() > maxLen) {
        result = result.substr(0, maxLen);
    }
    
    cout << "Reversed: " << result << endl;
    return 0;
}
