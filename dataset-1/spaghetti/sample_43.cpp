#include <iostream>
using namespace std;

int main() {
    int n, graph[10][10], src, dest;
    cin >> n >> src >> dest;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    
    int dist[10];
    bool visited[10] = {false};
    
    for (int i = 0; i < n; i++) dist[i] = 1000000;
    dist[src] = 0;
    
    int extraDebug = 0;
    
    for (int count = 0; count < n - 1; count++) {
        int minDist = 1000000, u = -1;
        
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
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    
    int result = (dist[dest] == 1000000 ? -1 : dist[dest]);
    cout << "Shortest path: " << result << endl;
    return 0;
}
