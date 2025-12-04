#include <iostream>
using namespace std;

void solveNQueens(int board[][10], int col, int n, int& count) {
    if (col >= n) {
        count++;
        return;
    }
    for (int i = 0; i < n; i++) {
        bool safe = true;
        for (int k = 0; k < col; k++) {
            if (board[i][k] == 1) safe = false;
        }
        for (int k = 0; k < col && i - k >= 0; k++) {
            if (board[i - k - 1][col - k - 1] == 1) safe = false;
        }
        for (int k = 0; k < col && i + k < n; k++) {
            if (board[i + k + 1][col - k - 1] == 1) safe = false;
        }
        if (safe) {
            board[i][col] = 1;
            solveNQueens(board, col + 1, n, count);
            board[i][col] = 0;
        }
    }
}

int main() {
    int n = 4, board[10][10] = {0}, count = 0;
    solveNQueens(board, 0, n, count);
    cout << "Solutions for 4-Queens: " << count << endl;
    return 0;
}
