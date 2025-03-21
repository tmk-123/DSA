#include<bits/stdc++.h>

using namespace std;

// kahn algorithm
bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V + 1, 0);
    queue<int> q;

    for (int u = 1; u <= V; u++) {
        for (int& v : adj[u]) {
            inDegree[v]++;
        }
    }

    for (int i = 1; i <= V; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;

        for (int& v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }

    return cnt != V;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        
        vector<vector<int>> adj(V + 1);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        if (hasCycle(V, adj)) cout << "YES\n";
        else cout << "NO\n";
    }
}