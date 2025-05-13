#include <bits/stdc++.h>
using namespace std;

int minCount;
int n, s;
vector<int> a;

void Try(int idx, int sum, int count) {
    if (sum == s) {
        minCount = min(minCount, count);
        return;
    }

    for (int i = idx; i < n; i++) {
        if (count < minCount && sum + a[i] <= s) {
            Try(i + 1, sum + a[i], count + 1); 
        }
    }
}



int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        a.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.rbegin(), a.rend());

        minCount = INT_MAX;
        Try(0, 0, 0);

        if (minCount == INT_MAX) cout << -1 << endl;
        else cout << minCount << endl;
    }
}
