#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E, s, t;
        cin >> V >> E >> s >> t;

        vector<vector<int>> adj(V + 1);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        queue<int> q;
        q.push(s);
        vector<bool> visited(V + 1, false);
        vector<int> parent(V + 1, -1);
        visited[s] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int& v : adj[u]) {
                if (!visited[v]) {
                    parent[v] = u;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        if (parent[t] == -1) {
            cout << -1 << endl;
            continue;
        }

        vector<int> path;
        for (int u = t; u != -1; u = parent[u]) {
            path.push_back(u);
        }
        for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
        cout << endl;
    }
}