#include<bits/stdc++.h>

using namespace std;

int dp[1001][10001];

void solve() {
    for (int i = 0; i <= 1000; i++) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000007;
        }
    }
}

int main() {
    solve();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
}