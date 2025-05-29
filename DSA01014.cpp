#include<bits/stdc++.h>

using namespace std;

int n, k, s;

void Try(int id, int cnt, int sum, int& res) {
    if (cnt == k) {
        if (sum == s) res++;
        return;
    }

    for (int i = id; i <= n; i++) {
        if (i + sum <= s) {
            cnt++;
            sum += i;
            Try(i + 1, cnt, sum, res);
            cnt--;
            sum -= i;
        }
    }
}

int main() {
    while (1) {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) break;
        int res = 0;
        Try(1, 0, 0, res);
        cout << res << endl;
    }
}