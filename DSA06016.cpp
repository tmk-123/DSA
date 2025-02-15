#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int maxA = 0, minB = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            maxA = max(maxA, x);
        }
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            minB = min(minB, x);
        }

        cout << (long long) maxA * minB << endl;
    }
}