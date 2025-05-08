#include<bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    vector<int> m(k);
    for (int i = 0; i < k; i++) m[i] = i;

    int res = INT_MAX;

    do {
        int minn = INT_MAX, maxx = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < k; j++) {
                temp += v[i][m[j]];
            }

            int value = stoi(temp);
            minn = min(minn, value);
            maxx = max(maxx, value);
        }
        res = min(res, maxx - minn);
    }
    while (next_permutation(m.begin(), m.end()));

    cout << res << endl;
}