#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, K;
        cin >> n >> K;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        long long cnt = 0;
        // i là số nhỏ nhất
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                long long sum = a[i] + a[j] + a[k];
                if (sum < K) {
                    cnt += (k - j); // mọi phần tử từ j + 1 đến k đều thỏa mãn với i, j, và thay thế k
                    j++;
                }
                else k--;
            }
        }

        cout << cnt << endl;
    }
}