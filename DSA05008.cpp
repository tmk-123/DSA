#include<bits/stdc++.h>

using namespace std;

string solve() {
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<bool> dp(s + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        // duyet nguoc tranh chong cheo
        for (int j = s; j >= a[i]; j--) {
            if (dp[j - a[i]]) dp[j] = true;
        }
        if (dp[s]) return "YES\n";
    }

    return "NO\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve();
    }
}