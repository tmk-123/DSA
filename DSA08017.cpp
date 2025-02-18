#include<bits/stdc++.h>

using namespace std;

bool compare(string a, string b) {
    if (a.length() == b.length()) return a > b;
    return a.length() > b.length();
}
void Try(vector<string> &v, string s, int n) {
    if (s.size() == n + 1) return;
    if (s.size() != 0) v.push_back(s);
    Try(v, s + '6', n);
    Try(v, s + '8', n);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> v;
        Try(v, "", n);
        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
    }
}