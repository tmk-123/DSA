#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_set<int> s;
        int Min = INT_MAX, Max = INT_MIN;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
            Min = min(Min, x);
            Max = max(Max, x);
        }

        int cnt = 0;
        for (int i = Min; i <= Max; i++) {
            if (s.find(i) == s.end()) cnt++;
        }

        cout << cnt << endl;
    }
}