#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool dfs(Node* root, int& levelLeaf, int level) {
    if (!root->left && !root->right) {
        if (levelLeaf == -1) {
            levelLeaf = level;
            return true;
        }
        else if (levelLeaf == level) return true;
        return false;
    }
    if (!root->left && root->right) return false;
    if (!root->right  && root->left) return false;
    return dfs(root->left, levelLeaf, level + 1) && dfs(root->right, levelLeaf, level + 1);
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

        int levelLeaf = -1;
        if (dfs(root, levelLeaf, 0)) cout << "Yes\n";
        else cout << "No\n";
    }
}