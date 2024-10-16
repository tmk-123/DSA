#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}