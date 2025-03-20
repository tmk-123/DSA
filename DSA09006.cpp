#include<bits/stdc++.h>

using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& parent) {
    visited[u] = true;
    for (auto& v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v, visited, adj, parent);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E, s, t;
        cin >> V >> E >> s >> t;
        vector<vector<int>> adj(V + 1);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V + 1, false);
        vector<int> parent(V + 1, -1), path;
        dfs(s, visited, adj, parent);
        if (!visited[t]) {
            cout << -1 << endl;
            continue;
        }

        for (int u = t; u != -1; u = parent[u]) path.push_back(u);
        for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
        cout << endl;
    }
} 