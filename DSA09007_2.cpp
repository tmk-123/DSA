#include<bits/stdc++.h>

using namespace std;

int n, m, s, t;

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
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : a[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

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