#include<bits/stdc++.h>

using namespace std;


void Try(int n, int k, int start, string s, vector<char> v) {
    if (k == 0) {
        cout << s << endl;
        return;
    }

    for (int i = start; i < n; i++) {
        Try(n, k - 1, i + 1, s + v[i], v);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<char> v;
        for (int i = 0; i < n; i++) {
            v.push_back('A' + i);
        }
        Try(n, k, 0, "", v);
    }
}