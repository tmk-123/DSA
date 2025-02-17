#include<bits/stdc++.h>

using namespace std;

long long findKnumber(long long n, long long k) {
    if (k == (1LL << (n - 1))) return n;
    if (k < (1LL << (n - 1))) return findKnumber(n - 1, k);
    return findKnumber(n - 1, k - (1LL << (n - 1)));
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << findKnumber(n, k) << endl;
    }
}