#include<bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> v(k + 1);
        for (int i = 1; i <= k; i++) {
            cin >> v[i];
        }  

        int idx = k;
        while (idx > 1 && v[idx] == v[idx - 1] + 1) {
            idx--;
        }

        if (idx == 1 && v[idx] == 1) {
            for (int i = 1; i <= k; i++) {
                cout << n - k + i << " ";
            }
            cout << endl;
        }
        else {
            v[idx]--;
            for (int i = idx + 1; i <= k; i++) {
                v[i] = n - k + i;
            }

            for (int i = 1; i <= k; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
}