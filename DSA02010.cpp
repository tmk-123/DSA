#include<bits/stdc++.h>

using namespace std;

int n, x;
vector<int> v;
bool found;

void Try(vector<int> path, int sum, int start) {
    if (sum == x) {
        found = true;
        cout << "[";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " ";
        }
        cout << "]";
        return;
    }

    for (int i = start; i < v.size(); i++) {
        if (sum + v[i] <= x) {
            path.push_back(v[i]);
            Try(path, sum + v[i], i);
            path.pop_back();
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        v.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());
        vector<int> path;
        found = false;
        Try(path, 0, 0);
        if (!found) cout << -1;
        cout << endl;
    }
}