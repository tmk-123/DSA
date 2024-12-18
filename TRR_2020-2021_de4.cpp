#include<iostream>

using namespace std;

int a[100];
int n, k;

void Try(int i) {
    if (i > k) {
        for (int i = 1; i <= k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        Try(i + 1);
    }
}

int main() {
    cin >> n >> k;
    a[0] = 0;
    Try(1);
}