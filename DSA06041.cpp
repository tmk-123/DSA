#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        bool found = false;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;      
            if (!found && m[a[i]] > n / 2) {
                found = true;
                cout << a[i] << endl;
            }
        }

        if (!found) cout << "NO" << endl;
    }
}