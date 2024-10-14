#include<iostream>
#include<vector>

using namespace std;

int a, b;

// hàm Load để tìm ra số chữ số tối thiểu thỏa mãn
int Load(int a, int b, vector<vector<int>> &dp){
    if (a > b || a < 0 || b < 0 || a > 900 || b > 8100) return -1;
    if (a == 0 && b == 0) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    
    int Min = 101;

    for (int i = 9; i >= 1; i--){
        int temp = Load(a - i, b - i * i, dp); // giống quay lui, trừ đi là giảm đi 1 chữ số
        // khi đệ quy đến cuối ra được Load(0, 0) = 0 , temp = 0, mỗi lần cập nhập thì temp tăng 1 hay tăng 1 chữ số
        if (temp != -1) Min = min(Min, temp + 1); // + 1 là cộng thêm 1 chữ số 
    }

    dp[a][b] = Min;
    return dp[a][b];
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> a >> b;
        vector<vector<int>> dp(901, vector<int>(901, -1));
        dp[0][0] = 0; // giá trị cơ sở
        int x = Load(a, b, dp);

        if (x == -1 || x > 100) cout << -1 << endl;
        else {
            while (a > 0 && b > 0){
                // khi đã biết số chữ số, lặp từ 1 đến 9 để nhỏ nhất. VD có 9, 9 ,1 thì in 199
                //mỗi lần in xong sẽ while tiếp và for lại từ đầu
                for (int i = 1; i <= 9; i++){
                    if (a >= i && b >= i * i && 1 + dp[a - i][b - i * i] == dp[a][b]){
                        cout << i;
                        a -= i;
                        b -= i * i;
                        break;
                    }
                }
            }
            cout << endl;
        }
    }
}