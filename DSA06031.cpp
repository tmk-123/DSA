#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i <= n - k; i++) {
            int maxSub = -1;
            for (int j = i; j < i + k; j++) {
                maxSub = max(maxSub, a[j]);
            }
            cout << maxSub << " ";
        }
        cout << endl;
    }
}