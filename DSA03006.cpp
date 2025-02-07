#include<bits/stdc++.h>

using namespace std;

bool check(vector<int> &a, int n) {
    vector<int> b = a;
    sort(b.begin(), b.end());

    if (a == b) return true;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && a[i] != b[n - i - 1]) return false;
    }

    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        if (check(v, n)) cout << "Yes\n";
        else cout << "No\n";
    }
}