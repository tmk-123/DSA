#include<bits/stdc++.h>

using namespace std;

char Try(long long n, string s, long long k) {
    if (k < s.size()) return s[k];
    // chuỗi gốc
    if (k < n / 2) return Try(n / 2, s, k);

    // ký tự đầu tiên của chuỗi quay vòng là ký tự cuối của chuỗi gốc 
    if (k == n / 2) return Try(n / 2, s, k - 1);

    // các ký tự còn lại dịch phải 1 ký tự so với chuỗi gốc
    if (k > n / 2) return Try(n / 2, s, k - n / 2 - 1);
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        string s;
        long long k;
        cin >> s >> k;
        k--;
        long long n = s.length();
        while (n <= k) {
            n *= 2;
        }
        cout << Try(n, s, k) << endl;
    }
}