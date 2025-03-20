#include<bits/stdc++.h>

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited);
    }
}

void dfs2(int u, vector<vector<int>>& adj, vector<bool>& visited, int s, int t) {
    visited[u] = true;
    for (int& v : adj[u]) {
        if ((u == s && v == t) || (v == s && u == t)) continue;
        if (!visited[v]) dfs2(v, adj, visited, s, t);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<pair<int, int>> edges;
        vector<vector<int>> adj(V + 1);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.push_back({u, v});
        }

        int baseComponent = 0;
        vector<bool> visited(V + 1, false);
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                baseComponent++;
                dfs(i, adj, visited);
            } 
        }

        for (auto& [u, v] : edges) {
            int component = 0;
            visited.assign(V + 1, false);
            for (int k = 1; k <= V; k++) {
                if (!visited[k]) {
                    component++;
                    dfs2(k, adj, visited, u, v);
                }
            }
            if (component > baseComponent) cout << min(u, v) << " " << max(v, u) << " ";
        }
        cout << endl;
    }
}