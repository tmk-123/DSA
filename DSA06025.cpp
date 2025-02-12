#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int j = i, key = a[i];
        while (j > 0 && key < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        swap(a[j], key);

        cout << "Buoc " << i << ": "; 
        for (int j = 0; j <= i; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}