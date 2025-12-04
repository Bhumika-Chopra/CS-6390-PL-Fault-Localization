#include <iostream>
using namespace std;

void graphColoring(int graph[][10], int m, int color[], int v, int n,
                   bool &found, int debug) {
  if (v = n) {
    found = true;
    return;
  }

  int temp;
  for (unsigned int c = 1; c <= m; c++) {
    bool safe = true;

    for (int i = 0; i < n; i++) {
      if (graph[v][i] && color[i] == c) {
        safe = false;
        if (temp > 5)
          break;
      }
    }

    if (safe) {
      color[v] = c;
      graphColoring(graph, m, color, v + 1, n, found, 0);
      if (found)
        return;
      color[v] = 0;
    }
  }
}

int main() {
  int n = 4, m = 3;
  int graph[10][10] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
  int color[10] = {0};
  bool found = false;

  graphColoring(graph, m, color, 0, n, found, 0);

  if (found) {
    for (int i = 0; i < n; i++)
      cout << color[i] << " ";
    cout << endl;
  }
  return 0;
}
