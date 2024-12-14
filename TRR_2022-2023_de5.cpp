#include<bits/stdc++.h>

using namespace std;

int k, n;

void in(vector<int> res) {
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void Try(int x, vector<int>& res, int a[]) {
    if (res.size() == k) {
        in(res);
        return;        
    }
    for (int i = x; i < n; i++) {
        if (i == 0 || a[i] < res[res.size() - 1]) {
            res.push_back(a[i]);
            Try(i + 1, res, a);
            res.pop_back();
        } 
    }
}

int main() {
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> res;
    Try(0, res, a);
}