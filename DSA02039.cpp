#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
int n;

void Try(int idx, vector<int> v, int sum) {
    if (sum == n) {
        res.push_back(v);
        return;
    }

    for (int i = idx; i >= 1; i--) {
        if (i + sum <= n) {
            v.push_back(i);
            Try(i, v, sum + i);
            v.pop_back();
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        res.clear();
        vector<int> v;
        Try(n, v, 0);
        sort(res.rbegin(), res.rend());
        cout << res.size() << endl;
        for (auto& x : res) {
            cout << "(";
            for (int i = 0; i < x.size(); i++) { 
                cout << x[i];
                if (i < x.size() - 1) cout << " ";
            }
            cout << ") ";
        }
        cout << endl;
    }
}