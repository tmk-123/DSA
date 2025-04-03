#include<bits/stdc++.h>

using namespace std;

vector<int> preorder;
vector<int> inorder;
int n;
unordered_map<int, int> inIndex;

void build(int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd) return;

    int rootVal = preorder[preIndex++];
    int rootIdx = inIndex[rootVal];

    build(inStart, rootIdx - 1, preIndex);
    build(rootIdx + 1, inEnd, preIndex);

    cout << rootVal << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        inorder.resize(n);
        preorder.resize(n);
        inIndex.clear();
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
            inIndex[inorder[i]] = i;
        }

        for (int i = 0; i < n; i++) cin >> preorder[i];

        int preIndex = 0;
        build(0, n - 1, preIndex);
        cout << endl;
    }
}