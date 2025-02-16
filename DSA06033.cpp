#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[i] = {x, i};
        }

        sort(v.begin(), v.end(), compare);
        int maxDistance = INT_MIN;
        int last = v[0].second;
        for (int i = 1; i < n; i++) {
            if (v[i].second - last > maxDistance) {
                maxDistance = v[i].second - last;
            }
            last = min(last, v[i].second);
        }

        cout << maxDistance << endl;
    }
}