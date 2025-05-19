#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            pq.push(a[i]);
        }

        long long sum = 0;
        while (pq.size() >= 2) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();

            long long z = (x + y) % mod;
            sum += z;
            sum %= mod;
            pq.push(z);
        }

        cout << sum << endl;
    }
}