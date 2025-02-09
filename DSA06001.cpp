#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);
        int b[n];
        int cnt = 0;
        for (int i = n - 1; i >= n / 2; i--) {
            b[cnt] = a[i];
            cnt += 2;
        }

        int count = 1;
        for (int i = 0; i < n / 2; i++) {
            b[count]= a[i];
            count += 2;
        }

        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}