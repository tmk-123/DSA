#include<bits/stdc++.h>

using namespace std;

void Try(int n, int k, vector<int> res, vector<int> a, int start, bool& found) {
    if (k == 0) {
        found = true;
        cout << "[";
        for (int i = 0; i < res.size(); i++) {
            if (i > 0) cout << " ";
            cout << res[i];
        }
        cout << "] ";
        return;
    }

    for (int i = start; i < n; i++) {
        if (k >= a[i]) {
            res.push_back(a[i]);
            Try(n, k - a[i], res, a, i + 1, found);
            res.pop_back(); 
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        bool found = false;
        Try(n, k, {}, a, 0, found);
        if (!found) cout << -1;
        cout << endl;
    }
}