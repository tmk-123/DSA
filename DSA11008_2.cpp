#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {} 
};

bool bfs(Node* root) {
    queue<Node*> q;
    q.push(root);
    bool found = false;
    int level = 0, levelLeaf = -1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto cur = q.front(); q.pop();
            if (!cur->left && !cur->right) {
                if (!found) {
                    levelLeaf = level;
                    found = true;
                }
                else if (levelLeaf != level) {
                    return false;
                }
            }

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        level++;
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
            int rootVal, value;
            char c;
            cin >> rootVal >> value >> c;

            if (!root) {
                root = new Node(rootVal);
                m[rootVal] = root;
            }

            Node* parent = m[rootVal];
            Node* child = new Node(value);  
            m[value] = child;
            if (c == 'L') parent->left = child;
            else parent->right = child;
        }

        cout << bfs(root) << endl;
    }
}