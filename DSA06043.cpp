#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int sum = accumulate(a.begin(), a.end(), 0);
        int leftSum = 0;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (leftSum * 2 == sum - a[i]) {
                found = true;
                cout << i + 1 << endl;
                break;
            } 
            leftSum += a[i];
        }

        if (!found) cout << -1 << endl;
    }
}