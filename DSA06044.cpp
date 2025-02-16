#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    sort(odd.begin(), odd.end());
    sort(even.rbegin(), even.rend());
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cout << odd[x++] << " ";
        else cout << even[y++] << " ";
    }
}