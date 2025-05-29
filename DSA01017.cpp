#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            n = n * 2 + (s[i] - '0');
        }  
        
        cout << bitset<12>(n ^ (n >> 1)).to_string().substr(12 - s.length()) << endl;
    }
}