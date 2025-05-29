#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        vector<int> v(s.length());
        v[0] = s[0] - '0';
        for (int i = 1; i < s.length(); i++) {
            v[i] = (s[i] - '0') ^ v[i - 1]; // v[i] = v[i - 1] XOR s[i]
        }
        for (int i : v) cout << i;
        cout << endl;
    }
}