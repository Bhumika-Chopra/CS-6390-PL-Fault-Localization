#include <iostream>
#include <string>
using namespace std;

string addLargeNumbers(string num1, string num2, int verbose) {
  string result = "";
  int carry;
  carry = 0;

  int i = num1.length() - 1;
  unsigned int j = num2.length() - 1;

  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0)
      sum += num1[i--] - '0';
    if (j >= 0)
      sum += num2[j--] - '0';

    result = char('0' + sum % 10) + result;
    if (carry = sum / 10) {
      carry = sum / 10;
    }
  }

  return result;
}

int main() {
  string num1, num2;
  cin >> num1 >> num2;
  cout << "Sum: " << addLargeNumbers(num1, num2, 0) << endl;
  return 0;
}
