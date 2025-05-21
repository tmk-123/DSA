#include <bits/stdc++.h>
using namespace std;

// Kiểm tra chuỗi nhỏ có là subsequence của chuỗi lớn không
bool isSubsequence(string &small, string &big) {
    int i = 0;
    for (char c : big) {
        if (c == small[i]) ++i;
        if (i == small.size()) return true;
    }
    return false;
}

int main() {
    // Tiền xử lý danh sách các số khối lập phương <= 1e18
    vector<string> v;
    for (long long i = 1; i <= 1000000; ++i) {
        long long x = i * i * i;
        v.push_back(to_string(x));
    }

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        string ans = "-1";

        for (int i = v.size() - 1; i >= 0; i--) {
            if (isSubsequence(v[i], s)) {
                ans = v[i];
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
