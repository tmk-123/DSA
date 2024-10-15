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
        vector<int> dp(n + 1, 0); // dp[i] : số cách để leo lên bậc thứ i
        dp[0] = 1; // 1 cách để đứng bậc 0(mặt đất)

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= k; j++){
                // đảm bảo nằm trong phạm vi
                if (i - j >= 0){
                    // số cách lên bậc i bằng tổng số cách lên i - j, i - j + 1, ... i - 1
                    dp[i] = (dp[i] + dp[i - j]) % mod;  
                }
            }
        }
        cout << dp[n] << endl;
    }
}