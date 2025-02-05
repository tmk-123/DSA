#include<bits/stdc++.h>

using namespace std;

int a[100], n;
vector<int> res;
vector<vector<int>> v;

void Try(int start) {
    if (res.size() >= 2) {
        v.push_back(res);
    }

    for (int i = start; i < n; i++) {
        if (res.empty() || (!res.empty() && a[i] > res[res.size() - 1])) {
            res.push_back(a[i]);
            Try(i + 1);
            res.pop_back();
        }
    }
}

string toString(vector<int> a) {
    string s;
    for (int i = 0; i < a.size(); i++) s += to_string(a[i]) + " ";
    return s;
}
bool compare(vector<int> a, vector<int> b) {
    return toString(a) < toString(b);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    Try(0);
    sort(v.begin(), v.end(), compare);

    for (auto x : v) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}