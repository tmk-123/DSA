#include<bits/stdc++.h>

using namespace std;

int V, E, M;
vector<vector<int>> adj;
vector<int> color;

bool isValid(int node, int c) {
    for (int& neighbor : adj[node]) {
        if (color[neighbor] == c) return false;
    }
    return true;
}

bool graphColoring(int node) {
    if (node == V + 1) return true;

    for (int c = 1; c <= M; c++) {
        if (isValid(node, c)) {
            color[node] = c;
            if (graphColoring(node + 1)) return true;
            color[node] = 0; // backtrack
        }
    }

    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E >> M;
        adj.assign(V + 100, vector<int>());
        color.assign(M + 100, 0);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (graphColoring(1)) cout << "YES\n";
        else cout << "NO\n";
    }
}