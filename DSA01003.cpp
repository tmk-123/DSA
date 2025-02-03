#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        } 

        int i = n - 1;
        while (i > 0 && a[i] > a[i + 1]) {
            i--;
        }

        if (i == 0) {
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            } 
            cout << endl;
        }
        else {
            for (int j = n; j >= i + 1; j--) {
                if (a[j] > a[i]) {
                    swap(a[j], a[i]);
                    break;
                }
            }

            int l = i + 1, r = n;
            while (l < r) {
                swap(a[l], a[r]);
                l++;
                r--;
            }

            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}