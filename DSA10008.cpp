#include<bits/stdc++.h>

using namespace std;

int V, E, start;

void dijkstra(vector<vector<pair<int, int>>>& adj) {
    vector<int> distance(V + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight, u
    
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > distance[u]) continue;

        // cập nhập cho các cạnh kề u
        for (auto& [v, w] : adj[u]) {
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E >> start;
        vector<vector<pair<int, int>>> adj(V + 1);
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dijkstra(adj);
    }
}