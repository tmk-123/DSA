#include<bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> v(k + 1);
        for (int i = 1; i <= k; i++) cin >> v[i];

        vector<int> temp = v;
        int idx = k;
        while (idx > 0 && v[idx] == n - k + idx) {
            idx--;
        }

        if (idx == 0) {
            cout << k << endl;
        }
        else {
            v[idx]++;
            for (int i = idx + 1; i <= k; i++) {
                v[i] = v[i - 1] + 1; 
            }

            int cnt = 0;
            set<int> Set(temp.begin(), temp.end());
            for (int i = 1; i <= k; i++) {
                if (!Set.count(v[i])) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
}