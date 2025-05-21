#include<bits/stdc++.h>

using namespace std;

// để có floor(a[i]/b[i] = n) thì n <= a[i]/b[i] < n + 1
// <=> n*b[i] <= a[i] <= (n + 1)b[i]
// <=> {b[i] <= a[i] / n 
//   && b[i] > a[i] / n + 1}
// nên a[i] / n luôn khác a[i] / n + 1, nếu bằng thì chắc chắn không ra
bool check(int n, vector<int>& a) {
    for (int x : a) {
        if (x / n == x / (n + 1)) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int minA = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        minA = min(minA, a[i]);
    }

    vector<int> b(n);
    // greedy từ i to đến nhỏ
    for (int i = minA; i >= 1; i--) {
        if (check(i, a)) {
            for (int j = 0; j < n; j++) {
                // b[j] nhỏ nhất có thương là i
                // vì a[i]/b[i] = x, thì a[i] / (b[i] - 1) = x + 1 , do b[i] là thương nhỏ nhất rồi
                b[j] = (a[j] / (i + 1)) + 1;
            }
            break;
        }
    }

    cout << accumulate(b.begin(), b.end(), 0);  
}