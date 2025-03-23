#include<bits/stdc++.h>

using namespace std;

vector<int> root;
vector<int> Rank;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int find(int u) {
    if (u != root[u]) root[u] = find(root[u]);
    return root[u];
}

bool unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU == rootV) return false;

    if (Rank[u] < Rank[v]) root[rootU] = rootV;
    else if (Rank[v] < Rank[u]) root[rootV] = rootU;
    else {
        root[rootV] = rootU;
        Rank[u]++;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<Edge> edges;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }        
        sort(edges.begin(), edges.end());

        Rank.assign(n + 1, 0);
        root.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) root[i] = i;

        vector<Edge> MST;
        int totalWeight = 0;
        
        for (Edge& e : edges) {
            if (unionSet(e.u, e.v)) {
                MST.push_back(e);
                totalWeight += e.w;
                if (MST.size() == n - 1) break;
            }
        }

        cout << totalWeight << endl;
    }
}