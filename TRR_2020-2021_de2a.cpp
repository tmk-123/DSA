#include<bits/stdc++.h>

using namespace std;

void Try(int n, string s) {
    if (s.length() == n) {
        cout << s << endl;
        return;
    }

    for (int i = '0'; i <= '1'; i++) {
        s += i;
        Try(n, s);
        s.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    Try(n, "");
}