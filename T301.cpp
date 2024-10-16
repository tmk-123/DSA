#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string a, b;
        cin >> a >> b;

        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // dp[i][j] lưu chiều dài lớn nhất giữa S1(0....i-1) và S2(0...j-1)
        // dp[0][0] là chưa lưu ký tự nào nên ta sẽ xét đến n và m

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                // hai ký tự giống nhau thì thêm ký tự đó vô
                if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        cout << dp[n][m] << endl;
    }
}