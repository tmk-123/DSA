#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<string> res;

void Try(vector<string> v, int start) {
    if (res.size() == k) {
        for (string s : res) {
            cout << s << " ";
        }
        cout << endl;
        return;
    } 

    for (int i = start; i < v.size(); i++) {
        res.push_back(v[i]);
        Try(v, i + 1);
        res.pop_back();
    }
}
int main() {
    cin >> n >> k;
    set<string> Set;
    string s;
    while (cin >> s) {
        Set.insert(s);
    }

    vector<string> v(Set.begin(), Set.end());
    Try(v, 0);
}