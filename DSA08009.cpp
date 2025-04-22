#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int s, t;
        cin >> s >> t;

        if (s >= t) {
            // Trường hợp chỉ cần trừ đi thôi
            cout << s - t << endl;
            continue;
        }

        vector<bool> visited(2 * t + 2, false);
        queue<pair<int, int>> q;
        q.push({s, 0});
        visited[s] = true;

        while (!q.empty()) {
            int n = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (n == t) {
                cout << cnt << endl;
                break;
            }

            if (n * 2 <= 2 * t && !visited[n * 2]) {
                q.push({n * 2, cnt + 1});
                visited[n * 2] = true;
            }

            if (n - 1 >= 1 && !visited[n - 1]) {
                q.push({n - 1, cnt + 1});
                visited[n - 1] = true;
            }
        }
    }
}
