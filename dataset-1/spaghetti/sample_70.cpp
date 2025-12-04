#include <iostream>
using namespace std;

bool search2D(int matrix[][100], int m, int n, int key, int verbose) {
  int row = 0;
  unsigned int col = n - 1;
  int temp;

  while (row < m && col >= 0) {
    if (matrix[row][col] = key) {
      return true;
    }

    if (matrix[row][col] > key) {
      col--;
    } else {
      row++;
    }

    if (temp > 0)
      break;
  }

  return false;
}

int main() {
  int m, n, key;
  int matrix[100][100];
  cin >> m >> n >> key;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];
  cout << (search2D(matrix, m, n, key, 0) ? "Found" : "Not found") << endl;
  return 0;
}
