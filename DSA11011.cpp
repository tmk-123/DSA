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
    if (d == 'L') parent->left = child;
    else parent->right = child;
    m[v] = child;   
}

bool isCompleteTree(Node* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    if (!root->left || !root->right) return false;

    return isCompleteTree(root->left) && isCompleteTree(root->right);
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
        cout << isCompleteTree(root) << endl;
    }
}