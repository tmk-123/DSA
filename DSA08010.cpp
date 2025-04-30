#include<bits/stdc++.h>

using namespace std;

int n;

int Try() {
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    
    q.push({n, 0});
    visited.insert(n);

    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();

        if (cur == 1) return cnt;

        if (visited.find(cur - 1) == visited.end()) {
            q.push({cur - 1, cnt + 1});
            visited.insert(cur - 1);
        }

        for (int i = 2; i * i <= cur; i++) {
            if (cur % i == 0) {
                int j = cur / i;
                int next = max(i, j);
                if (visited.find(next) == visited.end()) {
                    q.push({next, cnt + 1});
                    visited.insert(next);
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << Try() << endl;
    }
}