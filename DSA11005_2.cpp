#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};


int n;

Node* build(vector<int> levelOrder, vector<int> inOrder, int inStart, int inEnd, unordered_map<int, int> inIdx) {
    if (inStart > inEnd) return nullptr;

    Node* root = new Node(levelOrder[0]);
    int rootIdx = inIdx[root->val];

    vector<int> left, right;
    // duyệt hết các phần tử trong levelOrder, xem các phần tử nào nằm ở left, right để tạo level mới
    for (int i = 0; i < levelOrder.size(); i++) {
        int val = levelOrder[i];
        int pos = inIdx[val]; // vị trí tại inOrder
        
        // duyệt hết level order, nếu nằm trong inStart đến inEnd. nếu nằm bên trái thì là left, phải là right
        if (inStart <= pos && rootIdx > pos) left.push_back(val);
        else if (rootIdx < pos && inEnd >= pos) right.push_back(val);
    }

    root->left = build(left, inOrder, inStart, rootIdx - 1, inIdx);
    root->right = build(right, inOrder, rootIdx + 1, inEnd, inIdx);
    
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
        vector<int> levelOrder(n), inOrder(n);
        for (int i = 0; i < n; i++) cin >> inOrder[i];
        for (int i = 0; i < n; i++) cin >> levelOrder[i];

        unordered_map<int, int> inIdx;
        for (int i = 0; i < n; i++) {
            inIdx[inOrder[i]] = i;
        }

        Node* root = build(levelOrder, inOrder, 0, n - 1, inIdx);
        postOrder(root);
        cout << endl;
    }
}