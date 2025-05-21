#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long p, q;
    cin >> p >> q;
    
    // ta chon 1/x sao cho 1/x <= p/q hay x = ceil(q/p), sau đó trừ đi
    // p/q - 1/x = (p*x - q) / q*x, lặp lại đến khi p = 0
    vector<long long> res;
    while (p != 0) {
        long long x = ceil(q * 1.0 / p);
        res.push_back(x);
        
        p = p*x - q;
        q = q*x;
        long long GCD = __gcd(p, q);
        p /= GCD;
        q /= GCD;
    }

    for (int i = 0; i < res.size(); i++) {
        cout << "1/" << res[i];
        if (i < res.size() - 1) cout << " + ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}