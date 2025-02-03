#include<bits/stdc++.h>

using namespace std;

int n, a[100];
vector<vector<int>> res;
vector<int> v;
int cnt = 0;

void Try(int k, int start) {
    if (k == 0) {
        cnt++;
        res.push_back(v);
        return;
    }

    for (int i = start; i < n; i++) {
        if (k - a[i] >= 0) {
            v.push_back(a[i]);
            Try(k - a[i], i + 1);
            v.pop_back();
        }
    }
}
int main() {
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    Try(k, 0);
    sort(res.rbegin(), res.rend());
    for (auto x : res) {
        for (auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    } 
    cout << cnt << endl;
}