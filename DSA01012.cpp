#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < (1 << n); i++) {
            int gray = i ^ (i >> 1);
            cout << bitset<12>(gray).to_string().substr(12 - n) << " "; // từ 8 - n đến cuối
        }
        cout << endl;
    }
}