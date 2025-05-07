#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
int minRep = INT_MAX;
int overlap[10][10]; // lưu số ký tự lặp giữa 2 xâu

int countCommon(const string& a, const string& b) {
    int cnt = 0;
    set<char> s(a.begin(), a.end());
    for (char ch : b)
        if (s.count(ch)) cnt++;
    return cnt;
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // Tính trước số ký tự trùng giữa từng cặp
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            overlap[i][j] = countCommon(v[i], v[j]);

    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;

    do {
        int total = 0;
        for (int i = 0; i < n - 1; ++i) {
            total += overlap[perm[i]][perm[i + 1]];
            if (total >= minRep) break; // nhánh cắt
        }
        minRep = min(minRep, total);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << minRep << endl;
    return 0;
}
