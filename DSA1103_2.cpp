#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preOrder, inOrder;
int n;

Node* build(unordered_map<int, int>& inMap, int inStart, int inEnd, int& preIdx) {
    if (inStart > inEnd) return nullptr;

    Node* root = new Node(preOrder[preIdx++]);  
    int inIdx = inMap[root->val];

    root->left = build(inMap, inStart, inIdx - 1, preIdx);
    root->right = build(inMap, inIdx + 1, inEnd, preIdx);

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
        cin >> n;
        preOrder.resize(n);
        inOrder.resize(n);
        
        for (int i = 0; i < n; i++) cin >> inOrder[i];
        for (int i = 0; i < n; i++) cin >> preOrder[i];
        
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; i++) {
            inMap[inOrder[i]] = i;
        }

        int preIdx = 0;
        Node* root = build(inMap, 0, n - 1, preIdx);
        postOrder(root);
        cout << endl;
    }
}