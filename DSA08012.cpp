#include<bits/stdc++.h>

using namespace std;

int l, r;

bool check(int n) {
    set<int> Set;
    while (n) {
        if (Set.count(n % 10)) return false;
        Set.insert(n % 10);
        n /= 10;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        queue<int> q;
        int cnt = 0;
        for (int i = 1; i <= 5; i++) q.push(i);

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            if (l <= cur && cur <= r) cnt++;

            for (int i = 0; i <= 5; i++) {
                int next = cur * 10 + i;
                if (next > r) continue;
                if (check(next)) q.push(next);
            }
        }
        cout << cnt << endl;
    }
}