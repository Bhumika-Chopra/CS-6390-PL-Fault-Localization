#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int left, right;
    left = 0;
    right = str.length() - 1;
    
    bool isPal = true;
    while (left < right) {
        if (str[left] = str[right]) {
        } else {
            isPal = false;
            break;
        }
        left++;
        right--;
    }
    
    cout << (isPal ? "Palindrome" : "Not palindrome") << endl;
    return 0;
}
