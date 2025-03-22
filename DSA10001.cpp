#include<bits/stdc++.h>

using namespace std;

const int MAX = 505;
int n, m;
char v[MAX][MAX];
int visited[MAX][MAX][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct State {
    int x, y;
    int dir; // hướng(direction)
    int turn; // số lần đổi hướng(turn count)
};

bool bfs(pair<int, int> start, pair<int, int> target) {
    queue<State> q;

    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < 4; i++) {
        int nx = start.first + dx[i];
        int ny = start.second + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && v[nx][ny] != '*') {
            q.push({nx, ny, i, 0});
            visited[nx][ny][i] = 0;
        }
    }

    while (!q.empty()) {
        State curr = q.front(); q.pop();
        if (curr.x == target.first && curr.y == target.second) return true;

        for (int d = 0; d < 4; d++) {
            int nx = curr.x + dx[d];
            int ny = curr.y + dy[d];
            int newTurn = curr.turn + (curr.dir != d); // khác hướng thì +1

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (v[nx][ny] == '*') continue;
            if (newTurn > 2) continue;

            // nếu đã thăm ô này với số lần đổi hướng ít hơn thì bỏ qua 
            if (visited[nx][ny][d] != -1 && visited[nx][ny][d] <= newTurn) continue;

            visited[nx][ny][d] = newTurn;
            q.push({nx, ny, d, newTurn});
        }
    }
    
    return false;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m;
        pair<int, int> start, target;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
                if (v[i][j] == 'S') start = {i, j};
                if (v[i][j] == 'T') target = {i, j};
            }
        }        

        if (bfs(start, target)) cout << "YES\n";
        else cout << "NO\n";
    }
}