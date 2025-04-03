#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string v) : val(v) {}
};

TreeNode* buildTree(vector<string>& v, int i) {
    if (i >= v.size()) return nullptr;
    TreeNode* node = new TreeNode(v[i]);
    node->left = buildTree(v, 2 * i + 1);
    node->right = buildTree(v, 2 * i + 2);
    return node;
}

int dfs(TreeNode* root) {
    if (!root->left && !root->right) return (stoi(root->val));

    int l = dfs(root->left);
    int r = dfs(root->right);

    if (root->val == "+") return l + r;
    if (root->val == "-") return l - r;
    if (root->val == "*") return l * r;
    if (root->val == "/") return l / r;

    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        vector<string> v;
        string token;

        while (ss >> token) {
            v.push_back(token);
        }

        TreeNode* root = buildTree(v, 0);
        cout << dfs(root) << endl;
    }
}