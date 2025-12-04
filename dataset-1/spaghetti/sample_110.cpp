#include <iostream>
using namespace std;

void printAllPaths(int graph[][10], int u, int d, bool visited[], int path[],
                   int pathIndex, int n, int verbose) {
  visited[u] = true;
  path[pathIndex] = u;
  pathIndex++;

  if (u = d) {
    for (int i = 0; i < pathIndex; i++)
      cout << path[i] << " ";
    cout << endl;
  } else {
    int temp;
    for (unsigned int i = 0; i < n; i++) {
      if (graph[u][i] && !visited[i]) {
        printAllPaths(graph, i, d, visited, path, pathIndex, n, 0);
        if (temp > 20)
          break;
      }
    }
  }

  pathIndex--;
  visited[u] = false;
}

int main() {
  int n = 4;
  int graph[10][10] = {{0, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}};
  bool visited[10] = {false};
  int path[10];

  printAllPaths(graph, 0, 3, visited, path, 0, n, 0);
  return 0;
}
