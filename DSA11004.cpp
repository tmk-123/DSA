#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void insert(int u, int v, char d, unordered_map<int, Node*>& m) {
    Node* parent = m[u];
    Node* child = new Node(v);

    if (d == 'R') parent->right = child;
    else parent->left = child;
    m[v] = child;
}

void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << endl;
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
                if (root == nullptr) root = m[u];
            }
            insert(u, v, d, m);
        }
        levelOrder(root);
    }
}