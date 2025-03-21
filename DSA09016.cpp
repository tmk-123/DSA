#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& visited, int u) {
    visited[u] = 1;
    for (int& v : adj[u]) {
        if (visited[v] == 1) return true;
        if (visited[v] == 0 && dfs(adj, visited, v)) return true;
    }
    visited[u] = 2;
    return false; 
}

bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<int> visited(V + 1, 0);
    for (int i = 1; i <= V; i++) {
        if (dfs(adj, visited, i)) return true;
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
        }

        if (hasCycle(V, adj)) cout << "YES\n";
        else cout << "NO\n";
    }
}