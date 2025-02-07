#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        int sunday = s / 7;
        int day = ceil(m * s * 1.0 / n);
        if (day > s - sunday) cout << -1 << endl;
        else cout << day << endl;
    }
}