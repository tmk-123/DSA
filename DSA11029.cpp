#include<bits/stdc++.h>

using namespace std;

void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& path, vector<vector<int>>& res) {
    path.push_back(u);
    bool isLeaf = true;

    for (int& v : adj[u]) {
        if (v != parent) {
            isLeaf = false;
            dfs(v, u, adj, path, res);
        }
    }

    if (isLeaf) res.push_back(path);
    path.pop_back();
}

bool compare(vector<int> a, vector<int> b) {
    return a.back() < b.back();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> path;
        vector<vector<int>> res;
        dfs(1, -1, adj, path, res);

        sort(res.begin(), res.end(), compare);

        for (auto& p : res) {
            for (auto& x : p) cout << x << " ";
            cout << endl;
        }
    }
}