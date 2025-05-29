#include<bits/stdc++.h>

using namespace std;

int n;

void Try(int idx, vector<int> v, int sum) {
    if (sum == n) {
        cout << "(";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << " ";
        }
        cout << ") ";
        return;
    }    

    for (int i = idx; i >= 1; i--) {
        if (sum + i <= n) {
            v.push_back(i);
            Try(i, v, sum + i);
            v.pop_back();
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v;
        Try(n, v, 0);
        cout << endl;
    }
}