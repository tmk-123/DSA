#include<bits/stdc++.h>

using namespace std;

int n;
int v[100][100];
int res = INT_MAX;
vector<bool> visited(100, false);

void Try(int i, int sum, int cnt) {
    if (sum > res) return;
    if (cnt == n - 1) {
        res = min(res, sum + v[i][0]);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!visited[j]) {
            visited[j] = true;
            Try(j, sum + v[i][j], cnt + 1);
            visited[j] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    visited[0] = true;
    Try(0, 0, 0);
    cout << res;
}