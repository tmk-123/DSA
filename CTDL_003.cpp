#include<bits/stdc++.h>

using namespace std;

int maxCost = INT_MIN;
int n, w;
vector<int> res;

void Try(int idx, int sum, int cost, vector<int> ans, vector<int> c, vector<int> a) {
    if (maxCost < cost) {
        maxCost = cost;
        res = ans;
    } 

    for (int i = idx; i < n; i++) {
        if (a[i] + sum <= w) {
            ans[i] = 1;
            Try(i + 1, sum + a[i], cost + c[i], ans, c, a);
            ans[i] = 0;
        }
    }
}

int main() {
    cin >> n >> w;
    vector<int> c(n), a(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int j = 0; j < n; j++) cin >> a[j];
    vector<int> ans(n, 0);
    Try(0, 0, 0, ans, c, a);
    cout << maxCost << endl;
    for (auto x : res) {
        cout << x << " ";
    }
}