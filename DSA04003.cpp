#include<bits/stdc++.h>

using namespace std;

#define m 123456789

long long mul(long long n) {
    if (n == 0) return 1;
    long long x = mul(n / 2);
    if (n % 2 == 0) return (x * x) % m;
    return 2 * ((x * x) % m) % m;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << mul(n - 1) << endl;
    }
}