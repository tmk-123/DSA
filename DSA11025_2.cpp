#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* build(vector<int> v, int left, int right) {
    if (left > right) return nullptr;

    int mid = (left + right) / 2;
    Node* root = new Node(v[mid]);
    root->left = build(v, left, mid - 1);
    root->right = build(v, mid + 1, right);

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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        Node* root = build(a, 0, n - 1);
        preOrder(root);
        cout << endl;
    }
}