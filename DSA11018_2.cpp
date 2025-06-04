#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int n) {
    if (!root) return new Node(n);

    if (root->val < n) root->right = insert(root->right, n);
    else root->left = insert(root->left, n);

    return root;
}

void preOrder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
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
            root = insert(root, x);
        }

        preOrder(root);
        cout << endl;        
    }
}