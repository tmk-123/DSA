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

        vector<bool> visited(n + 100, false);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, visited, a);
            } 
        }

        cout << cnt << endl;
    }
}