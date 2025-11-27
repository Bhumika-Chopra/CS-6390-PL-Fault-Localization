#include <iostream>
#include <string>
using namespace std;

int countVowels(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    string str;
    cin >> str;
    cout << "Vowels: " << countVowels(str) << endl;
    return 0;
}
