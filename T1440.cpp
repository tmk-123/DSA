#include<iostream>
#include<vector>

using namespace std;

int m, n;
int a[100][100];
int count_ways;

int isSafe(int x, int y){
    if (x >= 0 && x < m && y >= 0 && y < n) return 1;
    return 0;
}
void backtracking(int x, int y){
    if (x == m - 1 && y == n - 1){
        count_ways++;
        return;
    }

    if (isSafe(x + 1, y)){
        backtracking(x + 1, y);
    }

    if (isSafe(x, y + 1)){
        backtracking(x, y + 1);
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> m >> n;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        count_ways = 0;
        backtracking(0, 0);
        cout << count_ways << endl;
    }
}