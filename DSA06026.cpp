#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 1;
    while (1) {
        bool ok = false;
        for (int j = 1; j < n; j++) {
            if (a[j] < a[j - 1]) {
                ok = true;
                swap(a[j - 1], a[j]);
            }
        }
        if (!ok) break;

        cout << "Buoc " << cnt++ << ": "; 
        for (int j = 0; j < n; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}