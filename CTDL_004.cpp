#include<bits/stdc++.h>

using namespace std;

int n, k;
int cnt = 0;

void Try(int id, vector<int> a, vector<int> ans) {
    if (ans.size() == k) {
        cnt++;
        return;
    }

    for (int i = id; i < a.size(); i++) {
        if (ans.empty() || a[i] > ans.back()) {
            ans.push_back(a[i]);
            Try(i + 1, a, ans);
            ans.pop_back();
        }
    }
}

int main() {
    
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans;
    Try(0, a, ans);
    cout << cnt << endl;
}