#include<iostream>

using namespace std;

void Try(int n) {
    int a[n + 1];
    for (int i = 1; i <= n; i++) a[i] = i;

    while (1) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " "; 
        }
        cout << endl;

        int i = n - 1;
        while (i > 0 && a[i] > a[i + 1]) {
            i--;
        }

        if (i == 0) return;
        int k = n; 
        while (a[i] > a[k]) k--;
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;

        int l = i + 1, r = n;
        while (l < r) {
            temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++;
            r--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    Try(n);    
}