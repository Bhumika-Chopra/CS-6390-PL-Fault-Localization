#include <iostream>
using namespace std;

int shortestPath(int graph[][10], int n, int src, int dest) {
    int dist[10];
    bool visited[10] = {false};
    for (int i = 0; i < n; i++) dist[i] = 1e9;
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int minDist = 1e9, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !visited[v]) {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    return dist[dest];
}

int main() {
    int n, graph[10][10], src, dest;
    cin >> n >> src >> dest;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    int result = shortestPath(graph, n, src, dest);
    cout << "Shortest path: " << (result == 1e9 ? -1 : result) << endl;
    return 0;
}
