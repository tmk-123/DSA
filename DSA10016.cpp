#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> parent;

struct Edge {
    int u, v;
    double w;
};

bool compare(Edge& a, Edge& b) {
    return a.w < b.w;
}

int find(int u) {
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
}

bool dsu(int u, int v) {
    int pu = find(u);
    int pv = find(v);

    if (pu == pv) return false;
    parent[pu] = pv;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<double, double>> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }

        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = p[i].first - p[j].first;
                double dy = p[i].second - p[j].second;
                double dist = sqrt(dx * dx + dy * dy);
                edges.push_back({i, j, dist});
            }
        }

        sort(edges.begin(), edges.end(), compare);

        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        double total = 0;
        for (Edge& e : edges) {
            if (dsu(e.u, e.v)) {
                total += e.w;
            }
        }
        cout << fixed << setprecision(6) << total << endl;
    }
}