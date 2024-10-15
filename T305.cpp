#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        int dp[n] = {0};
        dp[0] = a[0];
        int Max = a[0];

        for (int i = 1; i < n; i++){
            dp[i] = a[i];
            for (int j = 0; j < i; j++){
                if (a[i] > a[j]){
                    dp[i] = max(dp[j] + a[i], dp[i]);
                }
            }
            Max = max(Max, dp[i]);
        }

        cout << Max << endl;
    }
}