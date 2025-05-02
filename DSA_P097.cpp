#include<bits/stdc++.h>

using namespace std;

const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};

int bfs(pair<int, int> start, pair<int, int> end, set<pair<int, int>>& valid) {
    queue<pair<pair<int, int>, int>> q;
    set<pair<int, int>> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [cur, dist] = q.front(); q.pop();
        int x = cur.first, y = cur.second;

        if (cur == end) return dist;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            pair<int, int> next = {nx, ny};
            if (valid.count(next) && !visited.count(next)) {
                visited.insert(next);
                q.push({next, dist + 1});
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int xA, yA, xB, yB;
        cin >> xA >> yA >> xB >> yB;

        int n;
        cin >> n;

        set<pair<int, int>> valid;
        for (int i = 0; i < n; i++) {
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            for (int j = y1; j <= y2; j++) {
                valid.insert({x, j});
            }
        }

        cout << bfs({xA, yA}, {xB, yB}, valid) << endl;
    }
}