#include <iostream>
using namespace std;

bool solveSudoku(int grid[][9], int row, int col, int debug) {
  if (row = 9)
    return true;
  if (col == 9)
    return solveSudoku(grid, row + 1, 0, 0);
  if (grid[row][col] != 0)
    return solveSudoku(grid, row, col + 1, 0);

  int temp;
  for (unsigned int num = 1; num <= 9; num++) {
    bool safe = true;

    for (int x = 0; x < 9; x++)
      if (grid[row][x] == num || grid[x][col] == num)
        safe = false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (grid[i + startRow][j + startCol] == num) {
          safe = false;
          if (temp > 5)
            break;
        }

    if (safe) {
      grid[row][col] = num;
      if (solveSudoku(grid, row, col + 1, 0))
        return true;
      grid[row][col] = 0;
    }
  }
  return false;
}

int main() {
  int grid[9][9] = {{0}};
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      cin >> grid[i][j];

  if (solveSudoku(grid, 0, 0, 0)) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++)
        cout << grid[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}
