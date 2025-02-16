#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<int> increasing(n, 1);
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                increasing[i] = increasing[i - 1] + 1;
            }
        }

        vector<int> decreasing(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                decreasing[i] = decreasing[i + 1] + 1;
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            maxLen = max(maxLen, increasing[i] + decreasing[i] - 1);
        }

        cout << maxLen << endl;
    }
}