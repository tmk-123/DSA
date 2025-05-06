#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n;
vector<string> res;

void dfs(string path, int x, int y, vector<vector<int>>& a, vector<vector<bool>> visited) {
    visited[x][y] = true;
    if (x == n - 1 && y == n - 1) {
        res.push_back(path);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && a[nx][ny]){
            char c;
            if (i == 0) c = 'U';
            else if (i == 1) c = 'L';
            else if (i == 2) c = 'D';
            else c = 'R';

            dfs(path + c, nx, ny, a, visited);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
      
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        res.clear();
        dfs("", 0, 0, a, visited);
    
        if (res.empty()) cout << -1 << endl;
        else {
            sort(res.begin(), res.end());
            for (string s : res) cout << s << " ";
            cout << endl;
        } 
    }
}