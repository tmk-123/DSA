#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> prefix;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        prefix[u]++;
        prefix[v + 1]--;
    }

    map<int, int> m;
    int cur = 0;

    for (auto&[a, b] : prefix) {
        cur += b;
        m[a] = cur;    
    }

    int q;
    cin >> q;
    while (q--) {
        int c;
        cin >> c;
        
        auto it = m.upper_bound(c);
        if (it == m.begin()) cout << 0 << endl;
        else {
            --it;
            cout << it->second << endl;
        }
    }
}