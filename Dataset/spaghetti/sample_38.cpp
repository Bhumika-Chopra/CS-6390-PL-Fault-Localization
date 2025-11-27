#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux, int& moves) {
    if (n == 1) {
        moves++;
        return;
    }
    
    towerOfHanoi(n - 1, from, aux, to, moves);
    moves++;
    towerOfHanoi(n - 1, aux, to, from, moves);
}

int helperFunction(int x) {
    return x * 2;
}

int main() {
    int n, moves = 0;
    cin >> n;
    
    towerOfHanoi(n, 'A', 'C', 'B', moves);
    
    cout << "Moves: " << moves << endl;
    return 0;
}
