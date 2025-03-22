#include<bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<bool> visited;

bool dfs(int u, int parent) {
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u)) return true;
        }
        else if (v != parent) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E;
        adj.assign(V + 10, vector<int>());
        visited.assign(V + 10, false);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool found = false;
        for (int i = 1; i <= V; i++) {
            if (!visited[i] && dfs(i, -1)) {
                cout << "YES\n";
                found = true;
                break;
            }
        }

        if (!found) cout << "NO\n";
    }
}