#include<bits/stdc++.h>

using namespace std;

vector<int> Rank, root;

struct Edge {
    int u, v, w;
};

int find(int u) {
    if (u != root[u]) root[u] = find(root[u]);
    return root[u];
}

int djs(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU == rootV) return false;
    if (Rank[rootU] > Rank[rootV]) {
        Rank[rootU]++;
        root[rootV] = rootU;
    }
    else {
        Rank[rootV]++;
        root[rootU] = rootV;
    }
    return true;
}

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<Edge> edges;;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        Rank.assign(n + 1, 0);
        root.resize(n + 1);
        for (int i = 1; i <= n; i++) root[i] = i;
        
        sort(edges.begin(), edges.end(), compare);
        int mst = 0;
        for (auto e : edges) {
            if (djs(e.u, e.v)) {
                mst += e.w;
            }
        }
        cout << mst << endl;
    }
}