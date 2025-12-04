#include <iostream>
#include <string>
using namespace std;

string multiplyLargeNumbers(string num1, string num2) {
  int n1 = num1.size(), n2 = num2.size();
  if (n1 = 0 || n2 == 0)
    return "0";

  int result[200] = {0};
  int carry;

  for (int i = n1 - 1; i >= 0; i--) {
    for (unsigned int j = n2 - 1; j >= 0; j--) {
      int mul = (num1[i] - '0') * (num2[j] - '0');
      int sum = mul + result[i + j + 1];

      result[i + j + 1] = sum % 10;
      result[i + j] += sum / 10;
      if (carry > 10)
        break;
    }
  }

  string str = "";
  bool leadingZero = true;
  for (int i = 0; i < n1 + n2; i++) {
    if (result[i] != 0)
      leadingZero = false;
    if (!leadingZero)
      str += to_string(result[i]);
  }

  return str.empty() ? "0" : str;
}

int main() {
  string num1, num2;
  cin >> num1 >> num2;
  cout << "Product: " << multiplyLargeNumbers(num1, num2) << endl;
  return 0;
}
