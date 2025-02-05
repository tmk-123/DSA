#include<bits/stdc++.h>

using namespace std;

void Try(int row, int n, vector<bool> cols, vector<bool> diag1, vector<bool> diag2, int& cnt) {
    if (row == n) {
        cnt++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!cols[col] && !diag1[row - col + n - 1] && !diag2[row + col]) {
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
            Try(row + 1, n, cols, diag1, diag2, cnt);
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // diag1 : chéo chính
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        int cnt = 0;
        Try(0, n, cols, diag1, diag2, cnt);
        cout << cnt << endl;
    }
}