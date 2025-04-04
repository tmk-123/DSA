#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* build(vector<int>& inorder, vector<int>& levelOrder, int inStart, int inEnd, unordered_map<int, int>& inorderIndex) {
    if (inStart > inEnd) return nullptr;
    
    int rootVal = levelOrder[0];
    int index = inorderIndex[rootVal];
    Node* root = new Node(rootVal);
    
    vector<int> leftLevel, rightLevel;
    for (int i = 0; i < levelOrder.size(); i++) {
        int val = levelOrder[i];
        int pos = inorderIndex[val];
        if (pos < index && pos >= inStart) leftLevel.push_back(val);
        else if (pos > index && pos <= inEnd) rightLevel.push_back(val);
    }

    root->left = build(inorder, leftLevel, inStart, index - 1, inorderIndex);
    root->right = build(inorder, rightLevel, index + 1, inEnd, inorderIndex);
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
        vector<int> inorder(n), levelOrder(n);
        unordered_map<int, int> inorderIndex;

        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
            inorderIndex[inorder[i]] = i; 
        }

        for (int i = 0; i < n; i++) cin >> levelOrder[i];

        Node* root = build(inorder, levelOrder, 0, n - 1, inorderIndex);
        postOrder(root);
        cout << endl;
    }
}