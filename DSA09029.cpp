#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int V, E;
bool ok;

void DFS(int u, int count) {
    if (count == V) {
        ok = true;
        return;
    }
    visited[u] = true;
    for (int x : adj[u]) {
        if (!visited[x]) {
            DFS(x, count + 1);
        }
    }
    visited[u] = false; // Quay lui
}

bool hasHamiltonianPath() {
    ok = false;
    for (int start = 1; start <= V; start++) { 
        visited.assign(V + 1000, false);   
        DFS(start, 1);
        if (ok) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E;
        adj.assign(V + 1000, vector<int>());

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (hasHamiltonianPath()) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
