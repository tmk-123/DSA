#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, start;
        cin >> n >> m >> start;
        vector<vector<pair<int, int>>> a(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            a[u].push_back({v, w});
            a[v].push_back({u, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start}); // d, u;

        vector<int> dist(n + 1, INT_MAX);
        dist[start] = 0;

        vector<int> visited(n + 1, false);
        while (!pq.empty()) {
            auto [h, u] = pq.top(); pq.pop();
            visited[u] = true;

            for (auto [v, w] : a[u]) {
                if (!visited[v] && w + dist[u] < dist[v]) {
                    dist[v] = w + dist[u];
                    pq.push({dist[v], v});
                }
            }
        }

        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << dist[i] << " ";
        }
        cout << endl;
    }
}