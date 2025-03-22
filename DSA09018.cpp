#include<bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
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

        int baseComponent = 0;
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                dfs(i);
                baseComponent++;
            }
        }

        for (int i = 1; i <= V; i++) {
            visited.assign(V + 10, false);
            int component = 0;
            visited[i] = true;
            for (int j = 1; j <= V; j++) {
                if (!visited[j]) {
                    dfs(j);
                    component++;
                }   
            }

            if (component > baseComponent) cout << i << " ";
        }
        cout << endl;
    }
}