#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;

void Try(int idx, vector<int>& v, vector<int> ans, int sum) {
    if (!ans.empty()) {
        if (sum % 2 == 1) res.push_back(ans);
        if (idx >= v.size()) return;
    }

    for (int i = idx; i < v.size(); i++) {
        ans.push_back(v[i]);
        Try(i + 1, v, ans, sum + v[i]);
        ans.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end(), greater<>());
        
        res.clear();
        vector<int> ans;
        Try(0, v, ans, 0);
        sort(res.begin(), res.end());
        for (auto a : res) {
            for (int b : a) {
                cout << b << " ";
            }
            cout << endl;
        }
    }
}