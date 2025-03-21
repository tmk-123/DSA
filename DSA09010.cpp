#include<bits/stdc++.h>

using namespace std;

void dfs(vector<bool>& visited, vector<vector<int>>& adj, int u) {
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) dfs(visited, adj, v);
    }
}

bool isStronglyConnected(vector<vector<int>> adj, int n) {
    vector<bool> visited(n + 1, false);
    dfs(visited, adj, 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }

    vector<vector<int>> trans(n + 1);
    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
            trans[v].push_back(u);
    
    fill(visited.begin(), visited.end(), false);
    dfs(visited, trans, 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
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

        if (isStronglyConnected(adj, V)) cout << "YES\n";
        else cout << "NO\n";
    }
}