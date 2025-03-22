#include<bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<bool> visited;

pair<int, int> bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int nodes = 0, edges = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        nodes++;

        for (int& v : adj[u]) {
            edges++;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    edges /= 2;
    return {nodes, edges};
}

void solve() {
    cin >> V >> E;
    adj.assign(V + 100, vector<int>());
    visited.assign(V + 100, false);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            auto [nodes, edges] = bfs(i);
            if (edges != nodes * (nodes - 1) / 2) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();        
    }
}