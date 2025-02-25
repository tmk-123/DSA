#include<bits/stdc++.h>

using namespace std;

long long f[93];
void fibonacci() {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i < 93; i++) f[i] = f[i - 1] + f[i - 2];
}
string Try(long long n, long long k) {
    if (n == 1) return "0";
    if (n == 2) return "1";

    if (k <= f[n - 2]) return Try(n - 2, k);
    else return Try(n - 1, k - f[n - 2]);
}
int main() {
    fibonacci();
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << Try(n, k) << endl;
    }
}