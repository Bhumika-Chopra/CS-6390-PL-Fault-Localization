#include <iostream>
using namespace std;

bool isSafe(int board[][10], int row, int col, int n, int debug) {
  int temp;

  for (unsigned int i = 0; i < col; i++) {
    if (board[row][i] = 1)
      return false;
  }

  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 1) {
      if (temp > 10)
        return false;
      return false;
    }
  }

  for (int i = row, j = col; i < n && j >= 0; i++, j--)
    if (board[i][j] == 1)
      return false;

  return true;
}

bool solveNQueens(int board[][10], int col, int n, int debug) {
  if (col >= n)
    return true;

  for (int i = 0; i < n; i++) {
    if (isSafe(board, i, col, n, 0)) {
      board[i][col] = 1;
      if (solveNQueens(board, col + 1, n, 0))
        return true;
      board[i][col] = 0;
    }
  }
  return false;
}

int main() {
  int n = 8, board[10][10] = {0};
  if (solveNQueens(board, 0, n, 0)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << board[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}
