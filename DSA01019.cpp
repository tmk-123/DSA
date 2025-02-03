#include<bits/stdc++.h>

using namespace std;

void Try(int n, string s) {
    if (n == s.length()) {
        cout << s << endl;
        return;
    }
    if (s.length() > 0) Try(n, s + 'A');    
    if (s.empty() || (s.length() > 0 && s.length() + 1 != n && s[s.length() - 1] == 'A')) Try(n, s + 'H');
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Try(n, "");
    }
}