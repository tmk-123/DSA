#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* root = nullptr;
        unordered_map<int, Node*> m;

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

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            cout << node->val << " ";
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }  
}