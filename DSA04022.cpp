#include<bits/stdc++.h>

using namespace std;

long long len[26];
void prepare() {
    len[1] = 1;
    for (int i = 2; i < 26; i++) {
        len[i] = 2 * len[i - 1] + 1;
    }
}

char Try(long long n, long long k) {
    if (n == 1) return 'A';

    long long mid = len[n - 1] + 1;
    if (k == mid) return 'A' + n - 1;
    if (k < mid) return Try(n - 1, k);
    return Try(n - 1, k - mid);
}
int main() {
    prepare();
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << Try(n, k) << endl;
    }
}