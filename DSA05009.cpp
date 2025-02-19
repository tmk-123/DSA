#include<bits/stdc++.h>

using namespace std;

bool canPartition(vector<int> a, int i, int target) {
    if (target == 0) return true;
    if (i >= a.size() || target < 0) return false;

    return canPartition(a, i + 1, target - a[i]) || canPartition(a, i + 1, target);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % 2 == 1) cout << "NO" << endl;
        else {
            if (canPartition(a, 0, sum / 2)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
} 