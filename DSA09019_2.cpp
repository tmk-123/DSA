#include<bits/stdc++.h>

using namespace std;

bool dfs(int u, int parent, vector<bool>& visited, vector<vector<int>>& a) {
    visited[u] = true;
    for (int v : a[u]) {
        if (visited[v] && parent != v) {
            return true;
        }

        if (!visited[v]) {
            if (dfs(v, u, visited, a)) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n + 100);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        
        bool found = false;
        vector<bool> visited(n + 100, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dfs(i, -1, visited, a)) {
                cout << "YES\n";
                found = true;
                break;
            }
        }

        if (!found) cout << "NO\n";
    }
}