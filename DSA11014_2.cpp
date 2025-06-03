#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* build() {
    int n;
    cin >> n;
    unordered_map<int, Node*> m;
    Node* root = nullptr;
    while (n--) {
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
    return root;
}

int dfs(Node* root, Node* parent) {
    int sum = 0;
    if (!root) return 0;
    if (!root->left && !root->right) {
        if (root == parent->right) sum += root->val;
        else return 0;
    }

    sum += dfs(root->left, root);
    sum += dfs(root->right, root);

    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Node* root = build();
        cout << dfs(root, nullptr) << endl;
    }
}