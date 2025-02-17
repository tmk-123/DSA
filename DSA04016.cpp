#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, K;
        cin >> n >> m >> K;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        int i = 0, j = 0, k = 0;
        int c[n + m];
        while (j < n && k < m) {
            if (a[j] < b[k]) c[i++] = a[j++];
            else c[i++] = b[k++]; 
        }

        while (j < n) c[i++] = a[j++];
        while (k < m) c[i++] = b[k++];

        cout << c[K - 1] << endl;
    }
}