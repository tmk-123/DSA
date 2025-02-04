#include<bits/stdc++.h>

using namespace std;

char a[1000][1000];
int n, m;
int cnt = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int x, int y, vector<vector<bool>>& visited) {
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && a[newX][newY] == '#') {
            visited[newX][newY] = true;
            dfs(newX, newY, visited);
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
   
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && a[i][j] == '#') {
                cnt++;
                dfs(i, j, visited);
            }
        }
    }

    cout << cnt;
}