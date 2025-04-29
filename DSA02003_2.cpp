#include<bits/stdc++.h>

using namespace std;

int n;

vector<string> solve(vector<vector<int>> a) {
    if (a[0][0] == 0 || a[n - 1][n - 1] == 0) return {"-1"};
    queue<tuple<int, int, string>> q; //x, y, path
    q.push({0, 0, ""});
    vector<string> res;

    while (!q.empty()) {
        auto [x, y, path] = q.front();
        q.pop();

        if (x == n - 1 && y == n - 1) {
            res.push_back(path);
            continue;
        }

        if (x + 1 < n && a[x + 1][y] == 1) q.push({x + 1, y, path + 'D'});
        if (y + 1 < n && a[x][y + 1] == 1) q.push({x, y + 1, path + 'R'});
    }
    if (res.empty()) return {"-1"};
    return res;
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

        vector<string> res = solve(a);
        for (string s : res) cout << s << " ";
        cout << endl;
    }
}