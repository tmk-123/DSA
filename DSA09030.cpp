#include<bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<int> color;

bool BFS(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u]) return false;
        }
    }
    return true;
}

bool isBipartite() {
    color.assign(V + 1, -1);

    // ktra tung thanh phan lien thong
    for (int i = 1; i <= V; i++) {
        if (color[i] == -1) {
            if (!BFS(i)) return false;
        }
    }
    return true;
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

        if (isBipartite()) cout << "YES\n";
        else cout << "NO\n";
    }
}