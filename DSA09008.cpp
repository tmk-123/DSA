#include<iostream>
#include<vector>

using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[u] = true;
    for (auto& v : adj[u]) {
        if (!visited[v]) dfs(v, visited, adj);
    }
}

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
                dfs(i, visited, adj);
            }
        }
        cout << component << endl;
    }
} 