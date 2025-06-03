#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool dfs(Node* root) {
    if (!root->left && !root->right) return true;
    if (!root->left && root->right) return false;
    if (!root->right  && root->left) return false;
    return dfs(root->left) && dfs(root->right);
}   

int main() {
    int t;
    cin >> t;
    while (t--) {
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

        cout << dfs(root) << endl;
    }
}