#include <bits/stdc++.h>
using namespace std;

int bfs(int N, vector<vector<int>>& adj) {
    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q; // pair<node, depth>
    q.push({1, 0});
    visited[1] = true;
    int maxDepth = 0;

    while (!q.empty()) {
        auto [u, d] = q.front(); q.pop();
        maxDepth = max(maxDepth, d);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push({v, d + 1});
            }
        }
    }
    return maxDepth;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> adj(N + 1); // danh sách kề

        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << bfs(N, adj) << endl;
    }
    return 0;
}
