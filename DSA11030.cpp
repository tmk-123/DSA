#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> parent, depth;

void dfs(int u, int p) {
    for (int& v : adj[u]) {
        if (v != p) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int LCA(int u, int v) {
    while (u != v) {
        if (depth[u] > depth[v]) u = parent[u];
        else v = parent[v];
    }
    return u;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        adj.assign(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        parent.assign(n + 1, -1);
        depth.assign(n + 1, 0);

        dfs(1, 0);
        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            int ancestor = LCA(u, v);
            cout << (depth[u] + depth[v] - 2 * depth[ancestor]) << endl;
        }
    }
}