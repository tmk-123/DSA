#include<bits/stdc++.h>

using namespace std;

int n, x;
vector<int> v;
vector<vector<int>> res;

void Try(int idx, vector<int> path, int sum) {
    if (sum == x) {
        res.push_back(path);
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        if (sum + v[i] <= x) {
            path.push_back(v[i]);
            Try(i, path, sum + v[i]);
            path.pop_back();
        } 
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        v.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> v[i];
        
        res.clear();
        vector<int> path;
        Try(0, path, 0);

        if (res.empty()) cout << -1 << endl;
        else {
            sort(res.begin(), res.end());
            cout << res.size() << " ";
            for (auto a : res) {
                cout << "{";
                for (int i = 0; i < a.size(); i++) {
                    cout << a[i];
                    if (i < a.size() - 1) cout << " ";
                }
                cout << "} ";
            }
            cout << endl;
        }
    } 
}