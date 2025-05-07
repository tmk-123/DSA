#include<bits/stdc++.h>

using namespace std;

vector<int> prime;
vector<vector<int>> res;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void Try(int id, int n, int s, vector<int> a, vector<int>& v) {
    if (n == 0) {
        if (s == 0) res.push_back(v);
        return;        
    }

    for (int i = id; i < a.size(); i++) {
        if (s - a[i] >= 0) {
            v.push_back(a[i]);
            Try(i + 1, n - 1, s - a[i], a, v);
            v.pop_back();
        }
    }
}   

int main() {
    for (int i = 2; i <= 200; i++) {
        if (isPrime(i)) prime.push_back(i);
    }

    int t;
    cin >> t;
    while (t--) {
        int n, p, s;
        cin >> n >> p >> s;
        vector<int> a;
        for (int x : prime) if (x > p) a.push_back(x);

        res.clear();
        vector<int> v;
        Try(0, n, s, a, v);
        
        cout << res.size() << endl;
        sort(res.begin(), res.end());
        for (auto x : res) {
            for (int y : x) cout << y << " ";
            cout << endl;
        }
    }
}