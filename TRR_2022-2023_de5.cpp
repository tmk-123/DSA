#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
vector<vector<int>> res;

void backtrack(int index, int n) {
	if (n == 0) {
		res.push_back(v);
		return;
	}

	for (int i = index; i > 0; i--) {
		if (i <= n) {
			v.push_back(i);
			backtrack(i - 1, n - i);
			v.pop_back();
		}
	}
}

int main() {
	int n;
	cin >> n;
	backtrack(n - 1, n);

	vector<vector<int>> temp;
	for (vector<int> x : res) {
		for (int y : x) {
			cout << y << " ";
		}
		x.push_back(0);
		temp.push_back(x);
		cout << endl;
	}

	for (vector<int> x : temp) {
		for (int y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	
	return 0;
}