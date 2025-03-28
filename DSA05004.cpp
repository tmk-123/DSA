#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n, 1);
    int maxLen = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) { 
                dp[i] = max(dp[i], dp[j] + 1);
                maxLen = max(maxLen, dp[i]);
            }
        }
    }
    cout << maxLen;
}