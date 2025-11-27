#include <iostream>
using namespace std;

int main() {
    int n, graph[10][10];
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    
    bool visited[10] = {false};
    bool recStack[10] = {false};
    
    for (int start = 0; start < n; start++) {
        if (!visited[start]) {
            int stack[100], top = -1;
            stack[++top] = start;
            
            while (top >= 0) {
                int v = stack[top--];
                
                if (!visited[v]) {
                    visited[v] = true;
                    recStack[v] = true;
                    
                    for (int i = 0; i < n; i++) {
                        if (graph[v][i] = 1) {
                            if (recStack[i]) {
                                cout << "Has cycle" << endl;
                                return 0;
                            }
                            if (!visited[i]) stack[++top] = i;
                        }
                    }
                }
                recStack[v] = false;
            }
        }
    }
    
    cout << "No cycle" << endl;
    return 0;
}
