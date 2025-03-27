#include<bits/stdc++.h>

using namespace std;

int n, k, m;
vector<vector<int>> adj;
vector<int> peoples;
vector<bool> visited;

bool dfs(int u, int target) {
    if (u == target) return true;
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, target)) return true;
        }
    }
    return false;
}

bool solve(int target) {
   for (int i = 1; i <= k; i++) {
        visited.assign(n + 1, false);
        if (!dfs(peoples[i], target)) return false;
   }
   return true;
}

int main() {
    cin >> k >> n >> m;
    peoples.resize(k + 1);
    for (int i = 1; i <= k; i++) {
        int u;
        cin >> u;
        peoples[i] = u;
    }

    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (solve(i)) cnt++; 
    }
    cout << cnt;
}