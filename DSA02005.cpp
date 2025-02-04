#include<bits/stdc++.h>

using namespace std;

void Try(string res, string s, vector<bool>& visited) {
    if (res.size() == s.size()) {
        cout << res << " ";
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            Try(res + s[i], s, visited);
            visited[i] = false;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<bool> visited(s.length(), false);
        Try("", s, visited);  
        cout << endl;  
    }
}