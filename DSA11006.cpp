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

void bfs(Node* root) {
    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()) {
        int size = q.size();
        vector<int> v;
        for (int i = 0; i < size; i++) {
            Node* node = q.front(); q.pop();
            v.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        if (cnt % 2 == 1) {
            for (int i : v) cout << i << " ";
        }
        else {
            for (int i = size - 1; i >= 0; i--) {
                cout << v[i] << " ";
            }
        }
        cnt++;
    }
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
        bfs(root);
        cout << endl;
    }
}