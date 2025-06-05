#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
void dfs(int u, vector<vector<int>> adj, vector<int> path) {
    path.push_back(u);
    bool isLeaf = true;
    for (int v : adj[u]) {
        isLeaf = false;
        dfs(v, adj, path);
    }
    if (isLeaf) res.push_back(path);
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
        }

        res.clear();
        vector<int> path;
        dfs(1, adj, path);
        
        sort(res.begin(), res.end(), compare);
        for (auto x : res) {
            for (int y : x) {
                cout << y << " ";
            }
            cout << endl;
        }
    }
}