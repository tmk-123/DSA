#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int dp[n + 1] = {0};
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = k; j >= 1; j--) {
                if (i >= j) {
                    dp[i] += dp[i - j];
                    dp[i] %= 1000000007;
                }
            }
        }

        cout << dp[n] << endl;
    }
}