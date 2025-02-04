#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
void Try(vector<int> v) {
    if (v.empty()) return;

    vector<int> temp;
    res.push_back(v);
    for (int i = 0; i < v.size(); i++) {
        if (i > 0) {
            temp.push_back(v[i] + v[i - 1]);
        }
    }

    Try(temp);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        res.clear();
        Try(v);
        for (int i = res.size() - 1; i >= 0; i--) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j > 0) cout << " ";
                cout << res[i][j];
            }
            cout << "]" << " ";
        }
        cout << endl;
    }
}