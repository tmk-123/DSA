#include<bits/stdc++.h>

using namespace std;

void Try(int n, int k, int cnt, string s) {
    if (n == s.length()) {
        if (cnt == k) cout << s << endl;
        return;
    }

    Try(n, k, cnt, s + '0');
    Try(n, k, cnt + 1, s + '1');
}
int main() {
    int t;
    cin >> t;
    while (t--) {
       int n, k;
       cin >> n >> k;
       Try(n, k, 0, "");
    }
}