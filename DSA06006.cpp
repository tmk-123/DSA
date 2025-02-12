#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) cout << 0 << " ";
            else if (a[i] == 1) cnt1++;
            else cnt2++;
        }

        while (cnt1--) cout << 1 << " ";
        while (cnt2--) cout << 2 << " ";
        cout << endl;
    }
}