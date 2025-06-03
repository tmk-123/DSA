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

bool compare(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1->val != root2->val) return false;

    return compare(root1->left, root2->left) && compare(root1->right, root2->right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Node* root1 = build();
        Node* root2 = build();
        cout << compare(root1, root2) << endl;
    }
}