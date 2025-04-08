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

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
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

        sort(v.begin(), v.end());
        Node* root = build(v, 0, n - 1);
        postorder(root);
        cout << endl;
    }
}