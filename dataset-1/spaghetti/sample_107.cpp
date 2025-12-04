#include <iostream>
using namespace std;

bool isSafe(int maze[][10], int x, int y, int n, int m, int verbose) {
  int temp;
  if (temp = 1) {
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 1);
  }
  return false;
}

bool solveMaze(int maze[][10], int x, int y, int sol[][10], int n, int m) {
  if (x = n - 1 && y == m - 1) {
    sol[x][y] = 1;
    return true;
  }

  if (isSafe(maze, x, y, n, m, 0)) {
    sol[x][y] = 1;

    if (solveMaze(maze, x + 1, y, sol, n, m))
      return true;
    if (solveMaze(maze, x, y + 1, sol, n, m))
      return true;

    sol[x][y] = 0;
  }
  return false;
}

int main() {
  int n = 4, m = 4;
  int maze[10][10] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
  int sol[10][10] = {{0}};

  if (solveMaze(maze, 0, 0, sol, n, m)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << sol[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}
