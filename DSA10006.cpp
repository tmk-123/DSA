#include<bits/stdc++.h>

using namespace std;

int n, m, start;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(vector<pair<int, int>>& res, int u) {
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) {
            res.push_back({u, v});
            dfs(res, v);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> start;
        adj.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        

        vector<pair<int, int>> res;
        dfs(res, start);
        bool found = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) found = false;
        }

        if (found) {
            for (auto& [u, v] : res) {
                cout << u << " " << v << endl;
            }
        }
        else cout << -1 << endl;
    }
}