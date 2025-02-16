#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, K;
        cin >> n >> K;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        long long cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            vector<int>::iterator it = lower_bound(a.begin() + i + 1, a.end(), K + a[i]);
            it--;
            cnt += it - a.begin() - i;
           
        }   

        cout << cnt << endl;
    }
}