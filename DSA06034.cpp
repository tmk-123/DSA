#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        long long cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            vector<long long>::iterator it1 = lower_bound(a.begin() + i + 1, a.end(), k - a[i]);
            vector<long long>::iterator it2 = upper_bound(a.begin() + i + 1, a.end(), k - a[i]);
            if (it1 != a.end()) cnt += it2 - it1;
        }

        cout << cnt << endl;    
    }
}