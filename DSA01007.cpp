#include<bits/stdc++.h>

using namespace std;

void Try(int n, string s) {
    if (n == s.length()) {
        cout << s << " ";
        return;
    }

    Try(n, s + 'A');
    Try(n, s + 'B');
}
int main() {
    int t;
    cin >> t;
    while (t--) {
       int n;
       cin >> n;
       Try(n, "");
       cout << endl;
    }
}