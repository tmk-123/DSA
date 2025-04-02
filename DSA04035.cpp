#include<bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

long long Try(long long a, long long n) {
    if (n == 0) return 1;
    if (n == 1) return a;

    long long x = Try(a, n / 2) % mod;
    if (n % 2 == 1) return a * (x * x % mod) % mod;
    return x * x % mod;
}

int main() {
    long long a, b;
    while (1) {
        cin >> a >> b;
        if (!a && !b) return 0;
        cout << Try(a, b) << endl;
    }
}