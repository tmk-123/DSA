#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        unordered_map<char, int> m;
        int maxFreq = 0;
        for (char c : s) {
            m[c]++;
            maxFreq = max(m[c], maxFreq);
        }
        
        int n = ceil(s.size() / 2.0);
        if (maxFreq <= n) cout << 1 << endl;
        else cout << -1 << endl;
    }
}