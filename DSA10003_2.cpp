#include<bits/stdc++.h>

using namespace std;

vector<int> Rank, parent;

int find(int u) {
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
}

bool DJS(int u, int v) {
    int U = find(u);
    int V = find(v);
    
    if (U == V) return false;
    if (Rank[U] > Rank[V]) {
        Rank[U]++;
        parent[V] = U;
    }
    else {
        Rank[V]++;
        parent[U] = V;
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edge;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edge.push_back({u, v});
        }

        Rank.assign(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        bool found = false;
        for (auto [u, v] : edge) {
            if (!DJS(u, v)) {
                found = true;
                break;
            } 
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
}