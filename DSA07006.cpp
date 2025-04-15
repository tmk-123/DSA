#include<bits/stdc++.h>

using namespace std;

set<string> res;
queue<string> q;

void Try(string s) {
    vector<pair<int, int>> p;
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            p.emplace_back(st.top(), i);
            st.pop();
        }
    }

    for (auto& [open, close] : p) {
        string newStr = s;
        newStr.erase(close, 1);
        newStr.erase(open, 1);

        if (!res.count(newStr)) {
            res.insert(newStr);
            q.push(newStr);
        }
    }
}

int main() {
    string s;
    cin >> s;
    q.push(s);
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        Try(cur);
    }

    for (const string& exp : res) {
        cout << exp << endl;
    }

    return 0;
}
