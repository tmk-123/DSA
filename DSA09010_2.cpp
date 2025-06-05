#include<bits/stdc++.h>

using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& a) {
    visited[u] = true;
    for (int v : a[u]) {
        if (!visited[v]) {
            dfs(v, visited, a);
        }
    }
}

bool solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 100);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    vector<bool> visited(n + 100, false);
    dfs(1, visited, a);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }

    vector<vector<int>> b(n + 100);
    visited.assign(n + 100, false);
    for (int i = 1; i <= n; i++) {
        for (int j : a[i]) {
            b[j].push_back(i);
        }
    }
    dfs(1, visited, b);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}