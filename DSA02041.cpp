#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<pair<int, int>> q;
        q.push({n, 0});
        while (!q.empty()) {
            auto [num, cnt] = q.front(); q.pop();
            if (num == 1) {
                cout << cnt << endl;
                break;
            }

            if (num % 3 == 0) q.push({num / 3, cnt + 1});
            if (num % 2 == 0) q.push({num / 2, cnt + 1});
            q.push({num - 1, cnt + 1});
        }
    }       
}