#include<bits/stdc++.h>

using namespace std;

char c;

void Try(vector<bool> visited, int n, string s) {
    if (s.length() == n) {
        if (c == 'D') {
            if (s[0] == 'A' || s[3] == 'A') cout << s << endl;
        }
        else {
            if (s.find("AE") != string::npos || s.find("EA") != string::npos || (s[0] == 'A' && s[n - 1] == 'E') || (s[0] == 'E' && s[n - 1] == 'A')) cout << s << endl;
        }
        return;
    }

    for (int i = 'A'; i <= c; i++) {
        if (!visited[i - 'A']) {
            visited[i - 'A'] = true;
            Try(visited, n, s + string(1, i));
            visited[i - 'A'] = false;
        }
    }
}
int main() {
    cin >> c;
    int n = c - 'A' + 1;
    vector<bool> visited(n, false);
    Try(visited, n, "");
}