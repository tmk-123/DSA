#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> digits) {
    vector<int> v[3];
    int sum = 0;
    for (int d : digits) {
        sum += d;
        v[d % 3].push_back(d);
    }

    int n = sum % 3;
    if (n % 3 == 1) {
        if (!v[1].empty()) {
            v[1].erase(min_element(v[1].begin(), v[1].end()));
        }
        else if (v[2].size() >= 2) {
            v[2].erase(min_element(v[2].begin(), v[2].end()));
            v[2].erase(min_element(v[2].begin(), v[2].end()));
        }
        else {
            cout << -1 << endl;
            return;
        }
    }
    else if (n % 3 == 2) {
        if (!v[2].empty()) v[2].erase(min_element(v[2].begin(), v[2].end()));
        else if (v[1].size() >= 2) {
            v[1].erase(min_element(v[1].begin(), v[1].end()));
            v[1].erase(min_element(v[1].begin(), v[1].end()));
        }
        else {
            cout << -1 << endl;
            return;
        }
    }

    vector<int> res;
    for (int i = 0; i < 3; i++) {
        for (int d : v[i]) {
            res.push_back(d);
        }
    }

    if (res.empty()) {
        cout << -1 << endl;
        return;
    }

    sort(res.begin(), res.end(), greater<int>());

    if (res[0] == 0) cout << 0 << endl;
    else {
        for (int d : res) cout << d;
        cout << endl;
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
        solve(v);
    }
}