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

bool dfs(Node* root, int depth) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int leftLevel = -1;
    
    while (!q.empty()) {
        auto [node, level] = q.front(); q.pop();

        if (!node->left && !node->right) {
            if (leftLevel == -1) leftLevel = level;
            else if (leftLevel != level) return false;
        }
        
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
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
            int u, v;
            char d;
            cin >> u >> v >> d;

            if (m.find(u) == m.end()) {
                m[u] = new Node(u);
                if (!root) root = m[u]; 
            }
            insert(u, v, d, m);
        }

        if (dfs(root, 0)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}