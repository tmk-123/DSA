#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == k) cnt++;
        }

        if (!cnt) cout << -1 << endl;
        else cout << cnt << endl;
    }
}