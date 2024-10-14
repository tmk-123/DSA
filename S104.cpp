#include<iostream>
#include<vector>

#define ll long long
#define mod 1000000007

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int increasing[n], decreasing[n];

		for (int i = 0; i < n; i++) {
			increasing[i] = a[i];
			for (int j = 0; j < i; j++) {
				if (a[j] < a[i]) {
					increasing[i] = max(increasing[i], increasing[j] + a[i]);
				}
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			decreasing[i] = a[i];
			for (int j = n - 1; j > i; j--) {
				if (a[j] < a[i]) {
					decreasing[i] = max(decreasing[i], decreasing[j] + a[i]);
				}
			}
		}

		int Max = 0;
		for (int i = 0; i < n; i++) {
			if (increasing[i] + decreasing[i] - a[i] > Max) {
				Max = max(Max, increasing[i] + decreasing[i] - a[i]);
			}
		}

		cout << Max << endl;
	}
}
