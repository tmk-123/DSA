#include<bits/stdc++.h>

using namespace std;

bool check(vector<int> v1, vector<int> v2) {
    for (int i = 0; i < 6; i++) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

vector<int> quay1(vector<int> v) {
    int temp = v[1];
    v[1] = v[0];
    v[0] = v[3];
    v[3] = v[4];
    v[4] = temp;
    return v;
} 

vector<int> quay2(vector<int> v) {
    int temp = v[1];
    v[1] = v[4];
    v[4] = v[5];
    v[5] = v[2];
    v[2] = temp;
    return v;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> v1(6), v2(6);
        for (int i = 0; i < 6; i++) cin >> v1[i];
        for (int i = 0; i < 6; i++) cin >> v2[i];

        queue<pair<vector<int>, int>> q;
        set<vector<int>> Set;
        q.emplace(v1, 0);
        Set.insert(v1);
        while (!q.empty()) {
            vector<int> v = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (check(v, v2)) {
                cout << cnt << endl;
                break;
            }

            vector<int> a = quay1(v), b = quay2(v);
            if (Set.count(a) == 0) {
                q.emplace(a, cnt + 1);
                Set.insert(a);
            }
            if (Set.count(b) == 0) {
                q.emplace(b, cnt + 1);
                Set.insert(b);
            }
        }
    }
}