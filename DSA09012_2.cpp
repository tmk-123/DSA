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

        int total = 0;
        vector<bool> visited(n + 100, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, visited, a);
                total++;
            }
        }

        for (int i = 1; i <= n; i++) {
            visited.assign(n + 1, false);
            visited[i] = true;
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (!visited[j]) {
                    cnt++;
                    dfs(j, visited, a);
                }
            }

            if (cnt > total) cout << i << " ";
        }
        cout << endl;
    }
}