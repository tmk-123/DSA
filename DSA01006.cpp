#include<bits/stdc++.h>

using namespace std;

void Try(int n, string s, vector<bool>& visited) {
    if (n == s.length()) {
        cout << s << " ";
        return;
    }

    // khong dung dieu kien dung theo n bởi n - 1 thì for cũng từ 1 -> n - 1
    for (int i = n; i >= 1; i--) {
        if (visited[i]) {
            visited[i] = false;
            Try(n, s + to_string(i), visited);
            visited[i] = true;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
       int n;
       cin >> n;
       vector<bool> visited(n + 1, true);
       Try(n, "", visited);
       cout << endl;
    }
}