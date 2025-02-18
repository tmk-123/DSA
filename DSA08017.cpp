#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<string> q;
        q.push("6");
        q.push("8");
        
        vector<string> res;
        while (!q.empty()) {
            string s = q.front();
            q.pop();

            if (s.size() > n) break;
            res.push_back(s);
            q.push(s + '6');
            q.push(s + '8');
        }

        for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
        cout << endl; 
    }
}