#include<bits/stdc++.h>

using namespace std;

void solve() {
    int s, d;
    cin >> s >> d;

    vector<int> v(d, 0);
    v[0] = 1;
    s--;

    for (int i = d - 1; i >= 0; i--) {
        if (s >= 9 - v[i]) {
            s -= 9 - v[i];
            v[i] += 9 - v[i];
        }
        else {
            v[i] += s;
            s = 0;
        }
    }

    if (s > 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < d; i++) cout << v[i];
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}