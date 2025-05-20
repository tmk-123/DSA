#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        priority_queue<int> pq;
        unordered_map<int, int> m;
        
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }
    
        for (auto [c, f] : m) {
            pq.push(f);
        }

        while (k) {
            int x = pq.top(); pq.pop();
            if (x > 0) pq.push(x - 1);
            k--;
        }

        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top() * pq.top();
            pq.pop();
        }

        cout << sum << endl;    
    }
}