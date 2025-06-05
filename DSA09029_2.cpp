#include<bits/stdc++.h>

using namespace std;

int n, m;

bool dfs(int u, vector<bool>& visited, vector<vector<int>>& a, vector<int>& res) {
    visited[u] = true;
    res.push_back(u);
    if (res.size() == n) return true;
    for (int v : a[u]) {
        if (!visited[v]) {
            if (dfs(v, visited, a, res)) return true;
        }
    }
    
    visited[u] = false;
    res.pop_back();
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        
        cin >> n >> m;
        vector<vector<int>> a(n + 100);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        
        bool found = false;
        for (int i = 1; i <= n; i++) {
            vector<bool> visited(n + 1, false);
            vector<int> res;
            if (dfs(i, visited, a, res)) {
                cout << 1 << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << 0 << endl;
    }
}