#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int d[105][105];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        d[u][v] = d[v][u] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (d[u][k] < INF && d[k][v] < INF) {
                    d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << d[x][y] << endl;
    }
}