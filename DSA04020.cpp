#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool found = false;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] == k) {
                found = true;
                cout << mid + 1 << endl;
                break;
            }
            else if (a[mid] > k) right = mid - 1;
            else left = mid + 1;
        }

        if (found) cout << "NO\n";
    }
}