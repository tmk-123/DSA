#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V + 10);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V + 10, false);
        int component = 0;
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                component++;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int u = q.front(); q.pop();

                    for (int& v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }
        cout << component << endl;
    }
} 