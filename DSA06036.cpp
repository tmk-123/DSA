#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, K;
        cin >> n >> K;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        bool found = false;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                long long sum = a[i] + a[j] + a[k];
                if (sum == K) {
                    cout << "YES\n";
                    found = true;
                    break;
                }
                else if (sum < K) j++;
                else k--;
            }
            if (found) break;
        }

        if (!found) cout << "NO\n";
    }
}