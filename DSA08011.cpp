#include<bits/stdc++.h>

using namespace std;

int n;
string a, b;
unordered_set<string> Set;

int BFS() {
    if (a == b) return 0;
    if (Set.count(b) == 0) return -1;

    int n = a.size();
    queue<pair<string, int>> q;
    q.push({a, 1});
    Set.erase(a);

    while (!q.empty()) {
        auto [s, cnt] = q.front(); q.pop();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            for (int j = 'A'; j <= 'Z'; j++) {
                s[i] = j;
                if (s == b) return cnt + 1;
                if (Set.count(s) != 0) {
                    Set.erase(s);
                    q.push({s, cnt + 1});
                    Set.erase(s);
                }
            }
            s[i] = c;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Set.clear();
        cin >> n >> a >> b;
        
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            Set.insert(s);
        }

        cout << BFS() << endl;
    }
}