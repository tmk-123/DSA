#include <bits/stdc++.h>

using namespace std;

vector<int> root, Rank;
int V, E;

int findRoot(int u) {
    if (u != root[u]) 
        root[u] = findRoot(root[u]); // Path compression
    return root[u];
}

bool unionSet(int u, int v) {
    int rootU = findRoot(u);
    int rootV = findRoot(v);
    if (rootU == rootV) return false; // Đã cùng tập → có chu trình

    // Union by rank để tối ưu
    if (Rank[rootU] > Rank[rootV]) root[rootV] = rootU;
    else if (Rank[rootU] < Rank[rootV]) root[rootU] = rootV;
    else {
        root[rootV] = rootU;
        Rank[rootU]++;
    }
    return true;
}

bool checkCycle(vector<pair<int, int>>& edges) {
    for (auto& [u, v] : edges) {
        if (!unionSet(u, v)) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E;
        root.assign(V + 1, 0);
        Rank.assign(V + 1, 0);
        vector<pair<int, int>> edges;
        for (int i = 1; i <= V; i++) root[i] = i;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        if (checkCycle(edges)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
