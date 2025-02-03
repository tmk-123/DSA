#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[k + 1], b[k + 1];
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            b[i] = a[i];
        }

        int index = k;
        while (index >= 1 && a[index] == n - k + index) {
            index--;
        }

        if (index == 0) {
            cout << k << endl;
        } 
        else {
            a[index]++;
            for (int i = index + 1; i <= k; i++) {
                a[i] = a[i - 1] + 1;
            }

            int count = 0;
            for (int i = 1; i <= k; i++) {
                bool found = false;
                for (int j = 1; j <= k; j++) {
                    if (a[i] == b[j]) {
                        found = true;
                        break;
                    }
                } 
                if (!found) count++;
            }
            cout << count << endl;
        }
    }
}