#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int u, int parent) {
    visited[u] = true;

    for (int& v : adj[u]) {
        if (!visited[v]) {
            if (dfs(adj, visited, v, u)) return true;
        }
        else if (v != parent) {
            return true;
        }
    }

    return false;
}

bool hasCycle(int V, vector<vector<int>>& adj) {
    for (int i = 1; i <= V; i++) {
        vector<bool> visited(V + 1, false);
        if (dfs(adj, visited, i, -1)) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        
        vector<vector<int>> adj(V + 1);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (hasCycle(V, adj)) cout << "YES\n";
        else cout << "NO\n";
    }
}