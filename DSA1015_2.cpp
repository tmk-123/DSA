#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(int rootVal, int value, char c, Node*& root) {
    if (!root) {
        root = new Node(rootVal);
        Node* child = new Node(value);
        if (c == 'L') root->left = child;
        else root->right = child;
    }
    else {
        if (root->val == rootVal) {
            Node* child = new Node(value);
            if (c == 'L') root->left = child;
            else root->right = child;
        }
        else {
            if (root->left) insert(rootVal, value, c, root->left);
            if (root->right) insert(rootVal, value, c, root->right);
        }
    }
}

int maxSum;
int dfs(Node* root) {
    if (!root) return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (root->right && root->left) {
        maxSum = max(maxSum, root->val + left + right);
        return root->val + max(left, right);
    }

    return (root->left ? left : right) + root->val;
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
            insert(u, v, d, root);          
        }
        maxSum = INT_MIN;
        dfs(root);
        cout << maxSum << endl; 
    }
}