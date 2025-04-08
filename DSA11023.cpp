#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int bfs(Node* root) {
    queue<Node*> q;
    q.push(root);
    int depth = -1;

    while (!q.empty()) {
        depth++;
        int size = q.size();
        while (size--) {
            Node* cur = q.front(); q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return depth;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        Node* root = nullptr;
        for (int x : v) {
            root = insert(root, x);
        }
        
        cout << bfs(root) << endl;
    }
}