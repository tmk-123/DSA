#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(int u, int v, char d, unordered_map<int, Node*>& m) {
    Node* parent = m[u];
    Node* child = new Node(v);
    if (d == 'R') parent->right = child;
    else parent->left = child;
    m[v] = child;
}

bool bfs(Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int maxDepth = -1;

    while (!q.empty()) {
        auto& [node, depth] = q.front();
        q.pop();

        if (node->left && !node->right) return false;
        if (!node->left && node->right) return false;
        if (!node->left && !node->right) {
            if (maxDepth == -1) maxDepth = depth;
            else if (maxDepth != depth) return false;
        }

        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, Node*> m;
        Node* root = nullptr;
        for (int i = 0; i < n; i++) {
            int u, v; char d;
            cin >> u >> v >> d;
            if (m.find(u) == m.end()) {
                m[u] = new Node(u);
                if (!root) root = m[u];
            }
            insert(u, v, d, m);
        }

        if (bfs(root)) cout << "Yes\n";
        else cout << "No\n";
    }
}