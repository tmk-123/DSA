#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, v;
        cin >> n >> v;

        int a[n]; // thể tích mỗi đồ vật
        for (int i = 0; i < n; i++) cin >> a[i];

        int c[n]; // giá trị mỗi đồ vật
        for (int i = 0; i < n; i++) cin >> c[i];

        // dp[j] lưu thể tích lớn nhất dung tích cái túi còn chứa được
        vector<int> dp(v + 1, 0);

        // lặp qua từng đồ vật
        for (int i = 0; i < n; i++){
            // xét từng thể tích (không bỏ qua thể tích nào, mỗi thể tích với mỗi trường hợp riêng của các túi trước)
            for (int j = v; j >= a[i]; j--){
                dp[j] = max(dp[j], dp[j- a[i]] + c[i]); // lấy túi hoặc không lấy phải trừ thể tích tăng giá trị
            }
        }
        
        cout << dp[v] << endl;
    }
}