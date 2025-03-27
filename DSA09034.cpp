#include<bits/stdc++.h>

using namespace std;

const int MAX = 105;
int n, m;
char a[MAX][MAX];
vector<vector<bool>> visited;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && a[nx][ny] == 'W') {
            dfs(nx, ny);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'W' && !visited[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt;
}