#include <iostream>
using namespace std;

void bfs(int graph[][10], int n, int start) {
    bool visited[10] = {false};
    int queue[100], front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    cout << "BFS: ";
    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";
        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}

int main() {
    int n, graph[10][10];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    bfs(graph, n, 0);
    return 0;
}
