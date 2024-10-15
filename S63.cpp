#include<iostream>

#define ll long long

using namespace std;

    // ví dụ : n = 1234, tính theo chữ số kết thúc
    // dp[0] = 1;
    // dp[1] = 12 + 2 = 1 * 10 + 2 * 2 = 14;
    // dp[2] = 123 + 23 + 3 = 14 * 10 + 3 * 3 = dp[1] * 10 + (s[i] - '0') * (i + 1) = 149;
    // dp[3] = 1234 + 234 + 34 + 4 = 149 * 10 + 4 * 4 = 1506;

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int n = s.length();
        ll dp[n];
        dp[0] = s[0] - '0';
        ll sum = dp[0];

        for (int i = 1; i < n; i++){
            dp[i] = dp[i - 1] * 10 + (s[i] - '0') * (i + 1);
            sum += dp[i];
        }

        cout << sum << endl; 
    }
}