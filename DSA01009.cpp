#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<string> res;

void Try(string s) {
    if (s.size() == n) {
        string temp = s;
        string t = string(k, 'A');
        string t1 = string(k + 1, 'A');
        if (s.find(t1) != string::npos) return;
        if (s.find(t) == string::npos) return;
        
        s.erase(s.find(t), k);
        if (s.find(t) != string::npos) return;
        res.push_back(temp);
        return;
    }

    Try(s + 'A');
    Try(s + 'B');
}

int main() {
    cin >> n >> k;
    Try("");
    cout << res.size() << endl;
    for (string s : res) {
        cout << s << endl;
    }
}