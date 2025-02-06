#include<bits/stdc++.h>

using namespace std;

char c;
int n;

void Try(char start, string s) {
    if (s.length() == n) {
        cout << s << endl;
        return;
    }

    for (char ch = start; ch <= c; ch++) {
        s.push_back(ch);
        Try(ch, s);
        s.pop_back();
    }
}
int main() {
    cin >> c >> n;
    Try('A', "");
}