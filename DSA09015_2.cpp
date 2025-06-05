#include<bits/stdc++.h>

using namespace std;

bool dfs(int u, vector<int>& visited, vector<vector<int>>& a) {
    visited[u] = 1;
    
    for (int v : a[u]) {
        if (visited[v] == 1) return true; 
        if (visited[v] == 0 && dfs(v, visited, a)) return true;
    }

    visited[u] = 2;
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
        }

        vector<int> visited(n + 1, 0);
        bool found = false;
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0 && dfs(i, visited, a)) {
                found = true;
                break;
            }
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
}