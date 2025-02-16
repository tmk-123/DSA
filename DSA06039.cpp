#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int > a(n);

        bool found = false;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (m[a[i]] > 1) {
                cout << a[i] << endl;
                found = true;
                break;
            }
        }

        if (!found) cout << "NO" << endl;
    }
}