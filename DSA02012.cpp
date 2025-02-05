#include<bits/stdc++.h>

using namespace std;

void Try(int n, int m, int x, int y, int& cnt) {
    if (x == n - 1 && y == m - 1) {
        cnt++;
        return;
    }

    if (x < n - 1) Try(n, m, x + 1, y, cnt);
    if (y < m - 1) Try(n, m, x, y + 1, cnt);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        int cnt = 0;
        Try(n, m, 0, 0, cnt);
        cout << cnt << endl;
    }
}