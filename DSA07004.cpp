#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int cnt = 0;
        while (!s.empty()) {
            if (s.find("()") == string::npos) {
                if (s[0] == ')') {
                    s[0] = '(';
                    cnt++;
                }
                if (s[s.length() - 1] == '(') {
                    s[s.length() - 1] = ')';
                    cnt++;
                }
            }
            else {
                s.erase(s.find("()"), 2);
            }
        }

        cout << cnt << endl;
    }
}