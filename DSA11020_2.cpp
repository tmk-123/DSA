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
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (v[i] <= v[i - 1]) {
                ok = false;
                break;
            }
        }      

        cout << ok << endl;
    }
}