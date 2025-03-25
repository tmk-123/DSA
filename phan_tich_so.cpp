#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int x[m];
    for (int i = 0; i < m; i++) cin >> x[i];

    vector<int> dp(n + 1, INT_MAX);
    vector<int> trace(n + 1, -1);

    dp[0] = 0;  

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= x[j] && dp[i - x[j]] + 1 < dp[i]) {
                dp[i] = dp[i - x[j]] + 1;
                trace[i] = x[j];  
            }
        }
    }

    vector<int> res;
    while (n > 0) {
        res.push_back(trace[n]);
        n -= trace[n];
    }
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
}