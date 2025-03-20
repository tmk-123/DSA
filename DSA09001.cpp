#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int u = 1; u <= V; u++) {
            cout << u << ": ";
            for (auto& neighbor : adj[u]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}