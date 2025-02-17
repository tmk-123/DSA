#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int maxSum = INT_MIN;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = max(a[i], dp[i - 1] + a[i]);
            maxSum = max(maxSum, dp[i]);
        }

        cout << maxSum << endl;
    }
}