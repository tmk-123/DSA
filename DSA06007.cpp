#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        b = a;
        sort(b.begin(), b.end());
        
        int l = 0;
        while (l < n && a[l] == b[l]) l++;

        int r = n - 1;
        while (r >= 0 && a[r] == b[r]) r--;

        cout << l + 1 << " " << r + 1 << endl;
    }
}
