#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push(freq[i]);
        }

        while (k-- && !pq.empty()) {
            int top = pq.top(); pq.pop();
            if (top > 1) pq.push(top - 1);
        }

        long long res = 0;
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            res += 1LL * x * x;
        }
        cout << res << endl;
    }
}