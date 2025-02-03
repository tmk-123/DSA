#include<bits/stdc++.h>

using namespace std;

vector<int> res;
void Try(int n, int start, int k, vector<int> v) {
    if (res.size() == k) {
        for (int x : res) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < n; i++) {
        res.push_back(v[i]);
        Try(n, i + 1, k, v);
        res.pop_back();
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    set<int> Set;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Set.insert(x);
    }

    vector<int> v(Set.begin(), Set.end());
    Try(v.size(), 0, k, v);
}   