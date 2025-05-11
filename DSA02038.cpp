#include<bits/stdc++.h>

using namespace std;

int n, k;
void Try(int idx, vector<int> v, vector<int> ans) {
    if (ans.size() >= k) {
        if (ans.size() == k) {
            for (int x : ans) {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        ans.push_back(v[i]);
        Try(i + 1, v, ans);
        ans.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int> ans;
        Try(0, v, ans);
    }      
}