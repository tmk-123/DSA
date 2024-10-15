#include<iostream>
#include<vector>

#define mod 1000000007

using namespace std;

int dp[1001][1001];

void prepare(){
    
    for (int i = 0; i < 1001; i++){
        for (int j = 0; j <= i; j++){
            if (j == i) dp[i][j] = 1;
            else if (j == 1 || j == i - 1) dp[i][j] = i;
            else{
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                dp[i][j] %= mod;
            }
            
        }
    }
}
int main(){
    prepare();
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;

        cout << dp[n][k] << endl;
    }
}