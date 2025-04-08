#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(int u, int v, char d, Node*& root) {
    if (!root) {
        root = new Node(u);
        Node* child = new Node(v);
        if (d == 'L') root->left = child;
        else root->right = child;
    }
    else {
        if (root->val == u) {
            Node* child = new Node(v);
            if (d == 'L') root->left = child;
            else root->right = child;
        }
        else {
            if (root->left) insert(u, v, d, root->left);
            if (root->right) insert(u, v, d, root->right);
        }
    }
}

void getInorder(Node* root, vector<int>& vals) {
    if (!root) return;
    getInorder(root->left, vals);
    vals.push_back(root->val);
    getInorder(root->right, vals);
}

void fill(Node* root, vector<int>& vals, int& i) {
    if (!root) return;
    fill(root->left, vals, i);
    root->val = vals[i++];
    fill(root->right, vals, i);
}

void printInorder(Node* root) {
    if (!root) return;  
    printInorder(root->left);
    cout << root->val << " ";   
    printInorder(root->right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* root = nullptr;
        for (int i = 0; i < n; i++) {
            int u, v;
            char d;
            cin >> u >> v >> d;
            insert(u, v, d, root);          
        }
        
        vector<int> vals;
        getInorder(root, vals);
        
        sort(vals.begin(), vals.end());

        int i = 0;
        fill(root, vals, i);
        printInorder(root);
        cout << endl;
    }
}