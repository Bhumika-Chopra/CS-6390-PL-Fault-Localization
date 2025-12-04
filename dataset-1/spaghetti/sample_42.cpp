#include <iostream>
using namespace std;

int main() {
    int n, graph[10][10];
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    
    bool visited[10] = {false};
    int queue[100], front = 0;
    unsigned int rear = 0;
    
    visited[0] = true;
    queue[rear++] = 0;
    
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
    return 0;
}
