#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Node* root = nullptr;
        unordered_map<int, Node*> m;
        for (int i = 0; i < n; i++) {
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

        int cnt = 0;
        queue<Node*> q;
        q.push(root);       
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            while (size--) {
                auto cur = q.front(); q.pop();
                v.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            if (cnt % 2 == 0) reverse(v.begin(), v.end());
            cnt++;
            for (int i : v) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
