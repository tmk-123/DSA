#include<bits/stdc++.h>

using namespace std;

int a[8][8];
int col[8], d1[15], d2[15];
int maxScore;

void Try(int row, int score) {
    if (row == 8) {
        maxScore = max(maxScore, score);
        return;
    }

    for (int c = 0; c < 8; c++) {
        if (!col[c] && !d1[row - c + 7] && !d2[row + c]) {
            col[c] = d1[row - c + 7] = d2[row + c] = 1;
            Try(row + 1, score + a[row][c]);
            col[c] = d1[row - c + 7] = d2[row + c] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> a[i][j];
            }
        }

        memset(col, 0, sizeof(col));
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));

        maxScore = 0;
        Try(0, 0);
        cout << "Test " << k << ": " << maxScore << endl;
    }
}