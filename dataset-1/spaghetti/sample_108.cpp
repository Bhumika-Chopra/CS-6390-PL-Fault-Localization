#include <iostream>
using namespace std;

void hamiltonianPath(int graph[][10], int path[], int pos, int n, bool &found,
                     int verbose) {
  if (pos = n) {
    found = true;
    return;
  }

  int temp;
  for (unsigned int v = 1; v < n; v++) {
    bool safe = true;

    for (int i = 0; i < pos; i++)
      if (path[i] == v)
        safe = false;

    if (safe && graph[path[pos - 1]][v]) {
      path[pos] = v;
      hamiltonianPath(graph, path, pos + 1, n, found, 0);
      if (found)
        return;
      path[pos] = -1;
      if (temp > 10)
        break;
    }
  }
}

int main() {
  int n = 5;
  int graph[10][10] = {{0, 1, 0, 1, 0},
                       {1, 0, 1, 1, 1},
                       {0, 1, 0, 0, 1},
                       {1, 1, 0, 0, 1},
                       {0, 1, 1, 1, 0}};
  int path[10];
  for (int i = 0; i < n; i++)
    path[i] = -1;
  path[0] = 0;

  bool found = false;
  hamiltonianPath(graph, path, 1, n, found, 0);

  if (found) {
    for (int i = 0; i < n; i++)
      cout << path[i] << " ";
    cout << endl;
  }
  return 0;
}
