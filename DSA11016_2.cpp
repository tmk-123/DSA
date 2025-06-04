#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(int u, int v, char c, Node*& root) {
    Node* child = new Node(v);

    if (!root) {
        root = new Node(u);
        if (c == 'L') root->left = child;
        else root->right = child;
    }
    else {
        if (u == root->val) {
            if (c == 'L') root->left = child;
            else root->right = child;
        }
        else {
            if (root->left) insert(u, v, c, root->left);
            if (root->right) insert(u, v, c, root->right);
        }
    }
}

void inOrder(Node* root, vector<int>& v) {
    if (!root) return;
    inOrder(root->left, v);
    v.push_back(root->val);
    inOrder(root->right, v);
}

void fill(Node*& root, vector<int> v, int& i) {
    if (!root) return;
    fill(root->left, v, i);
    root->val = v[i++];
    fill(root->right, v, i);
}

void out(Node* root) {
    if (!root) return;
    out(root->left);
    cout << root->val << " ";
    out(root->right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* root = nullptr;
        while (n--) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            insert(u, v, c, root);
        }

        vector<int> v;
        inOrder(root, v);
        sort(v.begin(), v.end());
        
        int i = 0;
        fill(root, v, i);
        out(root);
        cout << endl;
    }   
}