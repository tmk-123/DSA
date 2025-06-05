#include<bits/stdc++.h>

using namespace std;

int n, m, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<set<pair<int, int>>>>& b, vector<vector<int>>& v) {
    int cnt = 0;
    if (v[x][y] == 1) cnt++;
    visited[x][y] = true;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx > 0 && ny > 0 && nx <= n && ny <= n && !b[x][y].count({nx, ny}) && !visited[nx][ny]) {
            cnt += dfs(nx, ny, visited, b, v);
        }
    }

    return cnt;
}

int main() {
    cin >> n >> k >> m;
    vector<vector<set<pair<int, int>>>> b(n + 1, vector<set<pair<int, int>>>(n + 1));
    for (int i = 0; i < m; i++) {
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        b[x][y].insert({z, t});
        b[z][t].insert({x, y});
    }

    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        v[x][y] = 1;
    }

    vector<int> res;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                int cnt = dfs(i, j, visited, b, v);
                res.push_back(cnt); 
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
        for (int j = i + 1; j < res.size(); j++) {
            ans += res[i] * res[j];
        }
    }

    cout << ans;
}