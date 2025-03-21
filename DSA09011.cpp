#include<bits/stdc++.h>

using namespace std;

int n;
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void dfs(int x, int y, vector<vector<int>>& adj, int n, int m) {
    adj[x][y] = 0;
    for (int i = 0; i < 9; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX > 0 && newY > 0 && newX <= n && newY <= m && adj[newX][newY]) {
            dfs(newX, newY, adj, n, m);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> adj[i][j];
            }
        }

        int component = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (adj[i][j]) {
                    component++;
                    dfs(i, j, adj, n, m);
                }
            }
        }

        cout << component << endl;
    }
}