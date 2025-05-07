#include<bits/stdc++.h>

using namespace std;

vector<bool> col, d1, d2;
vector<vector<int>> a;
int maxScore = 0;

void Try(int i, int score) {
    if (i == 8) {
        maxScore = max(maxScore, score);
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (!col[j] && !d1[i + j] && !d2[i - j + 7]) {
            col[j] = d1[i + j] = d2[i - j + 7] = true;
            Try(i + 1, score + a[i][j]);
            col[j] = d1[i + j] = d2[i - j + 7] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        a.assign(8, vector<int>(8));
        col.assign(8, false);
        d1.assign(15, false);
        d2.assign(15, false);
        maxScore = 0;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> a[i][j];
            }
        }

        Try(0, 0);
        cout << maxScore << endl;
    }
}