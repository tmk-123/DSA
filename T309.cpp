#include<iostream>
#include<vector>

#define mod 1000000007

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;

        vector<int> dp(n + 1, 0); // số cách lên bậc i
        dp[0] = 1; // số các đứng tại bậc 0 là 1

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= k; j++){
                if (i >= j){
                    dp[i] = (dp[i - j] + dp[i]) % mod; // bằng tổng số cách lên bậc i - j, i - j + 1, ..., i - 1
                }
            }
        }

        cout << dp[n] << endl;
    }
}