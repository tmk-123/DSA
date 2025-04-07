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

bool dfs(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    
    if (root1->val != root2->val) return false;

    return dfs(root1->left, root2->left) && dfs(root1->right, root2->right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, Node*> m1;
        Node* root1 = nullptr;
        for (int i = 0; i < n; i++) {
            int u, v;
            char d;
            cin >> u >> v >> d;
            if (m1.find(u) == m1.end()) {
                m1[u] = new Node(u);
                if (!root1) root1 = m1[u];
            }
            insert(u, v, d, m1);
        }

        cin >> n;
        unordered_map<int, Node*> m2;
        Node* root2 = nullptr;
        for (int i = 0; i < n; i++) {
            int u, v;
            char d;
            cin >> u >> v >> d;
            if (m2.find(u) == m2.end()) {
                m2[u] = new Node(u);
                if (!root2) root2 = m2[u];
            }
            insert(u, v, d, m2);
        }

        
        cout << dfs(root1, root2) << endl;
    }
}