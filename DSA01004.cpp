#include<bits/stdc++.h>

using namespace std;

void Try(int n, int k, int start, string s) {
    if (k == 0) {
        cout << s << " ";
        return;
    }

    for (int i = start; i <= n; i++) {
        Try(n, k - 1, i + 1, s + to_string(i));
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
       int n, k;
       cin >> n >> k;
       Try(n, k, 1, "");
       cout << endl;
    }
}