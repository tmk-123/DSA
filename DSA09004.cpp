#include<bits/stdc++.h>

using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[u] = true;
    cout << u << " ";
    for (auto& v : adj[u]) {
        if (!visited[v]) dfs(v, visited, adj);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E, start;
        cin >> V >> E >> start;
        vector<vector<int>> adj(V + 1);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V + 1, false);
        dfs(start, visited, adj);
        cout << endl;
    }
} 