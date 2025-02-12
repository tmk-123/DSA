#include<bits/stdc++.h>

using namespace std;

const long long m = 1e9 + 7;

long long power(long long a, long long b) {
    if (b == 0) return 1;

    long long x = power(a, b / 2);
    x = (x * x) % m;    
    if (b % 2 == 0) return x;
    return (a * x) % m;
}

long long reverseNum(long long n) {
    long long res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        long long r = reverseNum(n);
        cout << power(n, r) << endl;
    }
}