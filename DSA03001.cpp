#include<bits/stdc++.h>

using namespace std;

int main() {
    int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 9; i >= 0; i--) {
            int x = n / a[i];
            cnt += x;
            n -= x * a[i];
        }
        cout << cnt << endl;
    }
}