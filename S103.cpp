#include<iostream>
#include<vector>

#define ll long long
#define mod 1000000007

using namespace std;

vector<int> dp(10001, 1e9);
void prepare() {
	dp[0] = 0;

	for (int i = 1; i < 10000; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
			// nếu dp[i - j * j] có x cách để tạo tổng bình phương thì cộng thêm 1 (j * j) sẽ ra dp[i]
		}
	}
}

int main() {
	prepare();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
}
