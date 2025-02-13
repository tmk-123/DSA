#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> v;
        int cnt = 1;
        while (1) {
            bool ok = false;
            for (int j = 1; j < n; j++) {
                if (a[j] < a[j - 1]) {
                    ok = true;
                    swap(a[j - 1], a[j]);
                }
            }
            if (!ok) break;
            v.push_back(a);
        }

        for (int i = v.size() - 1; i >= 0; i--) {
            cout << "Buoc " << i + 1 << ": ";
            for (int j = 0; j < v[0].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}