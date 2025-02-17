#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        queue<unsigned long long> q;
        q.push(1);
        int cnt = 0;
        while (!q.empty()) {
            unsigned long long k = q.front();
            q.pop();
            if (k > n) break;
            cnt++;

            q.push(k * 10);
            q.push(k * 10 + 1);
        }

        cout << cnt << endl;
    }
}