#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[505][505];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct node {
    int x, y, cost;
    bool operator>(const node& other) const {
        return cost > other.cost;
    }
};

int dijkstra() {
    vector<vector<int>> distance(n, vector<int>(m, 1e9));
    priority_queue<node, vector<node>, greater<node>> pq;

    distance[0][0] = 0;
    pq.push({0, 0, a[0][0]});

    while (!pq.empty()) {
        node cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y, cost = cur.cost;

        if (x == n - 1 && y == m - 1) return cost;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (cost + a[nx][ny] < distance[nx][ny]) {
                    distance[nx][ny] = cost + a[nx][ny];
                    pq.push({nx, ny, distance[nx][ny]});
                }
            }
        }
    }

    return -1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        cout << dijkstra() << endl;
    }
} 