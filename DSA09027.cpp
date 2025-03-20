#include<bits/stdc++.h>

using namespace std;

bool dfs(int u, vector<bool>& visited, vector<vector<int>>& adj, int end) {
    visited[u] = true;
    if (u == end) return true;
    for (auto& v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, visited, adj, end)) return true;
        }
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
        
        int query;
        cin >> query;
        while (query--) {
            vector<bool> visited(V + 1, false);
            int s, t;
            cin >> s >> t;
            if (dfs(s, visited, adj, t)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
} 