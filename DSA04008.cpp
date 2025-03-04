#include<bits/stdc++.h>

using namespace std;

struct Matrix {
    long long m[2][2];
};

Matrix mul(Matrix a, Matrix b) {
    Matrix c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.m[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
                c.m[i][j] %= 1000000007;
            }
        }
    }
    return c;
}

Matrix power(Matrix a, int n) {
    if (n == 0) return {{0}};
    if (n == 1) return a;
    Matrix half = power(a, n / 2);
    half = mul(half, half);
    if (n % 2 == 1) half = mul(half, a);
    return half;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Matrix a;
        a.m[0][0] = 1; a.m[0][1] = 1;
        a.m[1][0] = 1; a.m[1][1] = 0;
        a = power(a, n - 1); // a ^ n-1
        cout << a.m[0][0] << endl;
    }
} 