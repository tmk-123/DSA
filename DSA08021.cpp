#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int minStep = 0;
        bool found = false;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == n - 1 && y == m - 1) {
                    cout << minStep << endl;
                    found = true;
                    break;
                }
                if (x + a[x][y] < n && !visited[x + a[x][y]][y]) {
                    q.push({x + a[x][y], y});
                    visited[x + a[x][y]][y] = true;
                }
                if (y + a[x][y] < m && !visited[x][y + a[x][y]]) {
                    q.push({x, y + a[x][y]});
                    visited[x][y + a[x][y]] = true;
                }
            }
            if (found) break;
            minStep++;
        }

        if (!found) cout << -1 << endl; 
    }
}