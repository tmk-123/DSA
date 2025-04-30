#include<bits/stdc++.h>

using namespace std;

const int MAX = 10000;
vector<bool> p;
int a, b;

void sang() {
    p.assign(MAX, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (p[i]) {
            for (int j = i * i; j < MAX; j += i) p[j]= false;
        }
    }
}

int main() {
    sang();
    int t;
    cin >> t;
    while (t--) {
       cin >> a >> b;
       vector<bool> visited(10000, false);
       queue<pair<int, int>> q;    
       q.push({a, 0});   
       visited[a] = true;

       while (!q.empty()) {
            auto [cur, cnt] = q.front(); q.pop();
            if (cur == b) cout << cnt << endl;
            string s = to_string(cur);
            for (int i = 0; i < 4; i++) {
                char origin = s[i];
                for (char c = '0'; c <= '9'; c++) {
                    if (i == 0 && c == '0') continue;
                    if (c == origin) continue;

                    s[i] = c;
                    int next = stoi(s);
                    if (!visited[next] && p[next]) {
                        visited[next] = true;
                        q.push({next, cnt + 1});
                    }
                }
                s[i] = origin;
            }        
       }
    }
}