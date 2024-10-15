#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        vector<ll> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= 3; j++){
                if (i >= j){
                    dp[i] += dp[i - j];
                }
            }
        }

        cout << dp[n] << endl;
    }
}