#include<bits/stdc++.h>

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited);
    }
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

        int baseComponent = 0;
        vector<bool> visited(V + 1, false);
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                baseComponent++;
                dfs(i, adj, visited);
            } 
        }

        for (int i = 1; i <= V; i++) {
            int component = 0;
            visited.assign(V + 1, false);
            visited[i] = true;
            
            for (int j = 1; j <= V; j++) {
                if (!visited[j]) {
                    component++;
                    dfs(j, adj, visited);
                }
            }

            if (component > baseComponent) cout << i << " ";
        }
        cout << endl;
    }
}