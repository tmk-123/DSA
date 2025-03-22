#include<bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
vector<int> path;

bool dfs(int u) {
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v)) return true;
        }
        else if (v != parent[u] && v == 1) {
            parent[v] = u;
            path.clear();
            int cur = u;
            path.push_back(1);
            while (cur != v) {
                path.push_back(cur);
                cur = parent[cur];
            }
            path.push_back(1);
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E;
        adj.assign(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        
        for (int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        visited.assign(V + 1, false);
        parent.assign(V + 1, -1);
        path.clear();
        if (dfs(1)) {
            for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
            cout << endl;
        }
        else cout << "NO\n";
    }
}