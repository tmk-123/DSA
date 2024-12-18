#include<iostream>

using namespace std;

void Try(int n, int k) {
    int a[k + 1];
    for (int i = 1; i <= k; i++) a[i] = i;

    while (1) {
        for (int i = 1; i <= k; i++) cout << a[i] << " ";
        cout << endl;

        int i = k;
        while (i > 0 && a[i] == n - k + i) i--;

        if (i == 0) return;

        a[i]++;
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[j - 1] + 1;
        } 
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    Try(n, k);
}