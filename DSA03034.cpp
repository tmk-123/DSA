#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, p;
        cin >> n >> m >> p;
        int a[n], b[m], c[p];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < p; i++) cin >> c[i];

        int i = 0, j = 0, k = 0;
        vector<int> res;
        while (i < n && j < m && k < p) {
            if (a[i] == b[j] && b[j] == c[k]) {
                res.push_back(a[i]);
                i++;
                j++;
                k++;
            }
            else if (a[i] < b[j]) i++;
            else if (b[j] < c[k]) j++;
            else k++;
        }

        if (res.empty()) cout << "NO" << endl;
        else {
            for (int x : res) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}