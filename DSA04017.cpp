#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < n - 1; j++) cin >> b[j];

        bool found = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != b[i]) {
                found = true;
                cout << i + 1 << endl;
                break;
            }
        }

        if (!found) cout << n - 1 << endl;
    }
}