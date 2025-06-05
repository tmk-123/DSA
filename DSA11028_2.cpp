#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

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

        int maxH = 0;
        queue<pair<int, int>> q;
        q.push({1, 0}); // node, height;
        while (!q.empty()) {
            auto [u, h] = q.front(); q.pop();

            for (int v : adj[u]) {
                maxH = max(maxH, h + 1);
                q.push({v, h + 1});
            }
        }

        cout << maxH << endl;
    }
}