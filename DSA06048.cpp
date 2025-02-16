#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int minValue = INT_MAX, minIndex = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (minValue > a[i]) {
                minValue = a[i];
                minIndex = i;
            }
        }

        cout << minIndex << endl;
    }
}