#include<bits/stdc++.h>

using namespace std;

void Try(int n, string s, vector<bool>& visited, vector<string>& v) {
    if (n == s.length()) {
        v.push_back(s);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            visited[i] = false;
            Try(n, s + to_string(i), visited, v);
            visited[i] = true;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bool> visited(n + 1, true);
        vector<string> v;
        Try(n, "", visited, v);

        string s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s += to_string(x);
        }  
        
        int cnt = 1;
        for (string x : v) {
            if (x == s) {
                cout << cnt << endl;
                break;
            }
            cnt++;
        }
    }
}