#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* build(vector<int>& v, int left, int right) {
    if (left > right) return nullptr;
    int mid = (left + right) / 2;
    Node* root = new Node(v[mid]);
    root->left = build(v, left, mid - 1);
    root->right = build(v, mid + 1, right);
    return root;
}

int countLeaf(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());
        Node* root = build(v, 0, n - 1);
        cout << countLeaf(root) << endl;
    }
}