#include<bits/stdc++.h>

using namespace std;

const int MAX = 105;
int n, k, m;
set<pair<int, int>> blocked[MAX][MAX];
bool hasSheep[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int dfs(int x, int y) {
    visited[x][y] = true;
    int cnt = hasSheep[x][y] ? 1 : 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && !visited[nx][ny] && blocked[x][y].count({nx, ny}) == 0) {
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

int main() {
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        blocked[u][v].insert({x, y});
        blocked[x][y].insert({u, v});
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        hasSheep[x][y] = true;
    }

    long long totalPairs = 1LL * k * (k - 1) / 2;
    long long samePairs = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                int sheepInComponent = dfs(i, j);
                samePairs += 1LL * sheepInComponent * (sheepInComponent - 1) / 2;
            }
        }
    }

    cout << totalPairs - samePairs;
}