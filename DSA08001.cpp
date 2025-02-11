#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<int> q;
        while (n--) {
            int type;
            cin >> type;
            if (type == 1) {
                cout << q.size() << endl;
            } else if (type == 2) {
                cout << (q.empty() ? "YES" : "NO") << endl;
            } else if (type == 3) {
                int x;
                cin >> x;
                q.push(x);
            } else if (type == 4) {
                if (!q.empty()) q.pop();
            } else if (type == 5) {
                cout << (q.empty() ? -1 : q.front()) << endl;
            } else if (type == 6) {
                cout << (q.empty() ? -1 : q.back()) << endl;
            }
        }
    }
}