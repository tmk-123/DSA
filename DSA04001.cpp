#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

long Try(long a, long b) {
    if (b == 1) return a;

    long x1 = Try(a, b / 2);
    if (b % 2 == 1) return ((a * x1) % mod * x1) % mod;
    else return (x1 * x1) % mod;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << Try(n, k) << endl;
    }
} 