#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x]++;
        }

        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].second; j++) {
                cout << v[i].first << " "; 
            }
        }
        cout << endl;
    }
}