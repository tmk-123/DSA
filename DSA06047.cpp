#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v[i] = x * x;
        }
        
        sort(v.begin(), v.end());
        bool found = false;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            while (j < n - 1) {
                if (binary_search(v.begin() + j + 1, v.end(), v[i] + v[j])) {
                    cout << "YES\n";
                    found = true;
                    break;
                }
                else j++;
            }
        }

        if (!found) cout << "NO\n";
    }
}