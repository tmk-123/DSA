#include<bits/stdc++.h>

using namespace std;

string res;

void Try(string s, int k) {
    if (k == 0) return;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] < s[j]) {
                swap(s[i], s[j]);
                res = max(res, s);
                Try(s, k - 1);
                swap(s[i], s[j]);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        res = s;
        Try(s, n);
        cout << res << endl;
    }
}