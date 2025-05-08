#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) 
        if (n % i == 0) return false;
    return true;
}

void Try(int idx, vector<int> v, vector<int> ans, int sum) {
    if (!ans.empty()) {
        if (isPrime(sum)) res.push_back(ans);
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
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        
        sort(v.begin(), v.end(), greater<>());
        res.clear();
        vector<int> ans;
        Try(0, v, ans, 0);

        sort(res.begin(), res.end());
        for (auto a : res) {
            for (int b : a) cout << b << " ";
            cout << endl;
        }
    }
} 