#include<bits/stdc++.h>

using namespace std;

const int MAX = 105;
int visited[MAX][MAX];

struct Cell {
    int x, y, steps;
};

int bfs(int N, vector<string>& v, int sx, int sy, int ex, int ey) {
    memset(visited, 0, sizeof(visited));
    queue<Cell> q;
    q.push({sx, sy, 0});
    visited[sx][sy] = 1;

    while (!q.empty()) {
        Cell cur = q.front(); q.pop();

        if (cur.x == ex && cur.y == ey) return cur.steps;

        // Duyệt theo 4 hướng (hàng, cột) không bị chắn
        // Đi lên
        for (int i = cur.x - 1; i >= 0; --i) {
            if (v[i][cur.y] == 'X') break;
            if (!visited[i][cur.y]) {
                visited[i][cur.y] = 1;
                q.push({i, cur.y, cur.steps + 1});
            }
        }
        // Đi xuống
        for (int i = cur.x + 1; i < N; ++i) {
            if (v[i][cur.y] == 'X') break;
            if (!visited[i][cur.y]) {
                visited[i][cur.y] = 1;
                q.push({i, cur.y, cur.steps + 1});
            }
        }
        // Đi trái
        for (int j = cur.y - 1; j >= 0; --j) {
            if (v[cur.x][j] == 'X') break;
            if (!visited[cur.x][j]) {
                visited[cur.x][j] = 1;
                q.push({cur.x, j, cur.steps + 1});
            }
        }
        // Đi phải
        for (int j = cur.y + 1; j < N; ++j) {
            if (v[cur.x][j] == 'X') break;
            if (!visited[cur.x][j]) {
                visited[cur.x][j] = 1;
                q.push({cur.x, j, cur.steps + 1});
            }
        }
    }

    return -1; // Không thể đến đích
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int result = bfs(N, v, a, b, c, d);
        cout << result << endl;
    }

    return 0;
}
