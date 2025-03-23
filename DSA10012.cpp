#include<bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> distance(n + 1, vector<int>(n + 1, INT_MAX));
        
        for (int i = 1; i <= n; i++) distance[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            distance[u][v] = 1;
        }

        double sum = 0;
        int cnt = 0;

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (distance[i][k] < INT_MAX && distance[k][j] < INT_MAX) {
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && distance[i][j] < INT_MAX) {
                    sum += distance[i][j];
                    cnt++;
                }
            }
        }

        cout << fixed << setprecision(2) << sum / cnt << endl;
    }
}