#include<bits/stdc++.h>

using namespace std;

long long f[93];

void fibo() {
    f[1] = f[2] = 1;
    for (int i = 3; i < 93; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}
char findChar(long long n, long long i) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (i <= f[n - 2]) return findChar(n - 2, i);
    return findChar(n - 1, i - f[n - 2]);
}

int main() {
    fibo();
    int t;
    cin >> t;
    while (t--) {
        long long n, i;
        cin >> n >> i;
        cout << findChar(n, i) << endl;
    }
}