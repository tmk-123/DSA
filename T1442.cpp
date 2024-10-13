#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int board[8][8];
int queen[8]; // queen[i] là cột chứ quân hậu hàng i, queen[i] = a thì a là cột , i là hàng
int max_score;

bool canPlace(int row, int col){
    // xét các hàng trên xem có thỏa mãn để đặt không
    for (int i = 0; i < row; i++){
        // abs để đường chéo ở mọi hướng
        if (queen[i] == col || abs(queen[i] - col) == abs(i - row))
            return false; 
    }
    
    return true;
}
void backtracking(int row, int score){
    if (row == 8){
        max_score = max(score, max_score);
        return;
    }

    // quay lui các cột trong 1 hàng
    for (int col = 0; col < 8; col++){
        if (canPlace(row, col)){
            queen[row] = col;
            backtracking(row + 1, score + board[row][col]);
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                cin >> board[i][j];
            }
        }

        max_score = 0;
        backtracking(0, 0);
        cout << max_score << endl;
    }
    return 0;
}