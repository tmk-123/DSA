#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, s, a[30];
int min_number;

void Try(int i, int sum_money, int cnt){
    // i là chỉ số trong mảng
    if (i == n || sum_money >= s || cnt == n){
        if (sum_money == s) min_number = min(min_number, cnt);
        return; 
    }
    Try(i + 1, sum_money, cnt); // bỏ qua tờ tiền đó
    Try(i + 1, sum_money + a[i], cnt + 1); // chọn tờ đó
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> s;
		min_number = 100;
		
		for (int i = 0; i < n; i++) cin >> a[i];
				
		Try(0, 0, 0);
		if (min_number != 100)
			cout << min_number << endl;
		else cout << -1 << endl;
	}	
}
