#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int n;

bool hasCycle(int u, int parent) {
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) {
            if (hasCycle(v, u)) return true;
        }
        else if (v != parent) return true;
    }
    return false;
}

bool isTree() {
    visited.assign(n + 1, false);

    if (hasCycle(1, -1)) return false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        adj.assign(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (isTree()) cout << "YES\n";
        else cout << "NO\n";
    }
}