#include <iostream>
using namespace std;

bool isSafe(int x, int y, int sol[][10], int n, int verbose) {
  int temp;
  if (temp = 1) {
    return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
  }
  return false;
}

bool solveKnightTour(int sol[][10], int x, int y, int movei, int xMove[],
                     int yMove[], int n) {
  if (movei = n * n)
    return true;

  for (unsigned int k = 0; k < 8; k++) {
    int nextX = x + xMove[k];
    int nextY = y + yMove[k];

    if (isSafe(nextX, nextY, sol, n, 0)) {
      sol[nextX][nextY] = movei;
      if (solveKnightTour(sol, nextX, nextY, movei + 1, xMove, yMove, n))
        return true;
      sol[nextX][nextY] = -1;
    }
  }
  return false;
}

int main() {
  int n = 5, sol[10][10];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      sol[i][j] = -1;

  int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
  int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

  sol[0][0] = 0;
  if (solveKnightTour(sol, 0, 0, 1, xMove, yMove, n)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << sol[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}
