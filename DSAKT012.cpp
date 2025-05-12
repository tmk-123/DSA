#include <bits/stdc++.h>
using namespace std;

int minCount = INT_MAX;
int n, s;
vector<int> a;

void Try(int idx, int sum, int count) {
    if (sum == s) {
        minCount = min(minCount, count);
        return;
    }

    for (int i = idx; i < n; i++) {
        if (count < minCount && sum + a[i] <= s) {
            Try(i + 1, sum + a[i], count + 1); // Chọn lại được a[i]
        }
    }
}

int main() {
    cin >> n >> s;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    Try(0, 0, 0);

    if (minCount == INT_MAX) cout << -1;
    else cout << minCount;
}
