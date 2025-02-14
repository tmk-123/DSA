#include<bits/stdc++.h>

using namespace std;

vector<bool> a(1000001, true);
void sang() {
    a[0] = a[1] = false;
    for (int i = 2; i <= 1000; i++) {
        if (a[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                a[j] = false;
            }
        }
    }
}
int main() {
    sang();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        bool found = false;
        for (int i = 2; i < n; i++) {
            if (a[i] && a[n - i]) {
                found = true;
                cout << i << " " << n - i << endl;
                break;
            }
        }

        if (!found) cout << -1 << endl;
    }
}