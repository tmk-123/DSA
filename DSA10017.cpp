#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
};

bool solve() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // ktra mọi điểm vì có thể không liên thông
    for (int start = 1; start <= V; start++) { 
        vector<int> distance(V + 1, INT_MAX);
        distance[start] = 0; 

        for (int i = 0; i < V - 1; i++) {
            for (auto& [u, v, w] : edges) {
                if (distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                }
            }
        }

        for (auto& [u, v, w] : edges) {
            if (distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                return true;
            }
        }
    }

    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}