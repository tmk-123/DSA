#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>

using namespace std;

void Try(int n, int k, int start, string s, vector<string>& v) {
    if (k == 0) {
        v.push_back(s);
        return;
    }

    for (int i = start; i <= n; i++) {
        Try(n, k - 1, i + 1, s + to_string(i), v);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> v;
        Try(n, k, 1, "", v);
        
        string s;
        for (int i = 0; i < k; i++) {
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