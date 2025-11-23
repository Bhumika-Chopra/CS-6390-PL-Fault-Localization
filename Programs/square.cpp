#include<iostream>
#include<cmath>

int square(int x) {
    return x * x;
}

int main() {
    int res = 0;
    int num = 5;
    std::cout << "The square of " << num << " is " << square(num) << std::endl;
    return 0;
}