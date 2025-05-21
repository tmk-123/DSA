#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long maxSum = 0;
    long long curSum = 0;
    for (int i = 0; i < n; i++) {
        long long x = (a[i] > 0) ? 2 * a[i] : 0;
        curSum = max(curSum + x, x);
        maxSum = max(maxSum, curSum); 
    }
    cout << maxSum;
}