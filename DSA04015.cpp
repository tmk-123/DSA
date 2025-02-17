#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        vector<long long>::iterator it = upper_bound(v.begin(), v.end(), x);
        if (it == v.begin()) cout << -1 << endl;
        else {
            cout << it - v.begin() << endl;
        }
    }
}