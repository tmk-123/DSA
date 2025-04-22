#include<bits/stdc++.h>

using namespace std;

int dx[8] = {2,2,1,1,-1,-2,-2,-1};
int dy[8] = {1,-1,-2,2,-2,-1,1,2};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        int startX = s1[0] - 'a', startY = s1[1] - '1';
        vector<vector<bool>> visited(8, vector<bool>(8, false));
        visited[startX][startY] = true;

        int targetX = s2[0] - 'a', targetY = s2[1] - '1';
        queue<tuple<int, int, int>> q;
        q.emplace(startX, startY, 0);
        while (!q.empty()) {
            auto [x, y, cnt] = q.front(); q.pop();
            if (x == targetX && y == targetY) {
                cout << cnt << endl;
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.emplace(nx, ny, cnt + 1);
                }
            }
        }
    }
}