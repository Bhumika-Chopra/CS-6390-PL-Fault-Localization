#include <iostream>
using namespace std;

void dfs(int graph[][10], int n, int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(graph, n, i, visited);
        }
    }
}

int main() {
    int n, graph[10][10];
    bool visited[10] = {false};
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    cout << "DFS: ";
    dfs(graph, n, 0, visited);
    cout << endl;
    return 0;
}
