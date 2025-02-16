#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < min1) {
                min2 = min1;
                min1 = a[i];
            }
            else if (a[i] < min2) min2 = a[i];
        }

        if (min2 == INT_MAX || min2 == min1) {
            cout << -1 << endl;
        }
        else cout << min1 << " " << min2 << endl;
    }
}