#include<bits/stdc++.h>

using namespace std;

int n, m, s, t;

void dfs(int u, vector<bool>&    visited, vector<vector<int>> a, vector<int>& parent) {
    visited[u] = true;
    for (int v : a[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v, visited, a, parent);
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m >> s >> t;
        vector<vector<int>> a(n + 1, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }       

        vector<int> parent(n + 1, -1);
        vector<bool> visited(n + 1, false);
        dfs(s, visited, a, parent);

        if (!visited[t]) {
            cout << -1 << endl;
            continue;
        }

        vector<int> res;
        for (int u = t; u != -1; u = parent[u]) {
            res.push_back(u);
        }
        for (int i = res.size() - 1; i >= 0; i--) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}