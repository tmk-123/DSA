#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* build(Node*& root, int n) {
    if (!root) return new Node(n);
    if (n < root->val) root->left = build(root->left, n);
    else root->right = build(root->right, n);
    return root;
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* root = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            root = build(root, x);
        }        

        postOrder(root);
        cout << endl;
    }
}