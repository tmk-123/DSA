#include<bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<bool> visited;

int dfs(int u) {
    visited[u] = true;
    int cnt = 1;
    for (int& v : adj[u]) {
        if (!visited[v]) {
            cnt += dfs(v);
        } 
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E;
        adj.assign(V + 100, vector<int>());    
        visited.assign(V + 100, false);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxSize = 0;
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                maxSize = max(maxSize, dfs(i));
            }
        }
        cout << maxSize << endl;
    }
}