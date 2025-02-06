#include<bits/stdc++.h>

using namespace std;

bool check(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (abs(s[i] - s[i - 1]) == 1) return false;
    }
    return true;
}
void Try(vector<bool> visited, int n, string s) {
    if (s.size() == n) {
        if (check(s)) cout << s << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            Try(visited, n, s + to_string(i));
            visited[i] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bool> visited(n + 1, false);
        Try(visited, n, "");
    }
}