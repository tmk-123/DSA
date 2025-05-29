#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<int>> ans;
vector<bool> visited;

void Try(int x, int sum, vector<vector<int>> v, vector<int> res) {
    if (x > n) {
        if (sum == k) ans.push_back(res);
        return;        
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && sum + v[x][i] <= k) {
            visited[i] = true;
            res.push_back(i);
            Try(x + 1, sum + v[x][i], v, res);
            res.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    visited.assign(n + 1, false);
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> res;
    Try(1, 0, v, res);
    cout << ans.size() << endl;
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}