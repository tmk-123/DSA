#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int cnt4 = 0, cnt7 = 0;
    cnt7 = n / 7;
    n = n % 7;

    if (n == 1 && cnt7 >= 1) {
        cnt4 += 2;
        cnt7 -= 1;
    }
    else if (n == 2 && cnt7 >= 2) {
        cnt4 += 4;
        cnt7 -= 2;
    }
    else if (n == 3 && cnt7 >= 3) {
        cnt7 -= 3;
        cnt4 += 6;
    }
    else if (n == 4 && cnt7 >= 4) {
        cnt7 -= 4;
        cnt4 += 8;
    }
    else if (n == 5 && cnt7 >= 1) {
        cnt7 -= 1;
        cnt4 += 3;
    }
    else if (n == 6 && cnt7 >= 2) {
        cnt7 -= 2;
        cnt4 += 5;
    }
    else if (n != 0) {
        cout << -1 << endl;
        return;
    }

    while (cnt4--) cout << 4;
    while (cnt7--) cout << 7;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
} 