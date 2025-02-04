#include<bits/stdc++.h>

using namespace std;

void Try(int x, int y, int n, vector<vector<int>> v, string s, bool& found) {
    if (x == 0 && y == 0 && v[x][y] == 0) {
        found = true;
        cout << -1;
        return;
    }
    if (x == n - 1 && y == n - 1) {
        found = true;
        cout << s << " ";
        return;
    }

    if (x < n - 1 && v[x + 1][y] == 1) Try(x + 1, y, n, v, s + 'D', found);
    if (y < n - 1 && v[x][y + 1] == 1) Try(x, y + 1, n, v, s + 'R', found);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        
        bool found = false;
        Try(0, 0, n, v, "", found);
        if (!found) cout << -1;
        cout << endl;
    }
}