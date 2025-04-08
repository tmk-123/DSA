#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(int u, int v, char d, Node*& root) {
    if (!root) {
        root = new Node(u);
        Node* child = new Node(v);
        if (d == 'L') root->left = child;
        else root->right = child;
    }
    else {
        if (root->val == u) {
            Node* child = new Node(v);
            if (d == 'L') root->left = child;
            else root->right = child;
        }
        else {
            if (root->left) insert(u, v, d, root->left);
            if (root->right) insert(u, v, d, root->right);
        }
    }
}

int maxSum = INT_MIN;

int dfs(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->val;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (root->right && root->left) {
        maxSum = max(maxSum, root->val + left + right);
        return root->val + max(left, right);
    }

    if (root->left) return root->val + left;
    return root->val + right;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* root = nullptr;
        for (int i = 0; i < n; i++) {
            int u, v;
            char d;
            cin >> u >> v >> d;
            insert(u, v, d, root);          
        }
        maxSum = INT_MIN;
        dfs(root);
        cout << maxSum << endl;
    }
}