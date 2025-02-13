#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        int j = i, key = a[i];
        while (j > 0 && key < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        swap(a[j], key);
        v.push_back(a);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i << ": ";
        for (int j = 0; j <= i; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}