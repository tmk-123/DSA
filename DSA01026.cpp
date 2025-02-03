#include<bits/stdc++.h>

using namespace std;

int n;
void Try(string s) {
    if (s.length() == n) {
        cout << s << endl;
        return;
    }
    if (!(s.length() > 3 && s[s.length() - 1] == '6' && s[s.length() - 2] == '6' && s[s.length() - 3] == '6') && !s.empty()) Try(s + '6');
    if (s.empty() || (s.length() > 0 && s[s.length() - 1] == '6') && !(s.length() + 1 == n)) Try(s + '8');
}
int main() {
    cin >> n;
    Try("");
}   