#include<iostream>
#include<vector>

using namespace std;

int n, k, s, cnt;
void backtracking(int curr, int sum, int number){
	if (sum == s && number == 0){
		cnt++;
		return;
	}
	
	for (int i = curr + 1; i <= n; i++){
		if (i + sum <= s){
			backtracking(i, sum + i, number - 1);
		}
	}
}
int main(){
	while (cin >> n >> k >> s){
		if (n == 0 && k == 0 && s == 0){
			break;
		}
		
		cnt = 0;
		backtracking(0, 0, k);
		cout << cnt << endl;
	}	
}
