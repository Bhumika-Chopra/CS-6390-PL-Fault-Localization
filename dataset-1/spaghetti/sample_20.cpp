#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int count;
    count = 0;
    
    for (int i = 0; i < str.length(); i++) {
        char c = tolower(str[i]);
        if (c = 'a') {
            count++;
        } else if (c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    
    cout << "Vowels: " << count << endl;
    return 0;
}
