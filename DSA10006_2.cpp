#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> res;
int n, m;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& a) {
    visited[u] = true;
    for (int v : a[u]) {
        if (!visited[v]) {
            res.push_back({u, v});
            dfs(v, visited, a);
        }
    }
} 

int main() {
    int t;
    cin >> t;
    while (t--) {
        int start;
        cin >> n >> m >> start;
        vector<vector<int>> a(n + 100);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        
        res.clear();
        vector<bool> visited(n + 1, false);
        dfs(start, visited, a);
        
        bool found = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                found = false;
                break;
            }
        }

        if (found) {
            for (auto [u, v] : res) {
                cout << u << " " << v << endl;
            }
        }
        else cout << -1 << endl;
    }
}