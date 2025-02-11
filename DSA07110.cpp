#include<bits/stdc++.h>

using namespace std;

bool check(string s) {
    stack<char> st;
    for (char c : s) {
        if ( (c == '}' || c == ']' || c == ')') && st.empty()) return false;
        
        if (c == ']') {
            if (st.top() == '[') st.pop();
            else return false;
        }
        else if (c == ')') {
            if (st.top() == '(') st.pop();
            else return false;
        }
        else if (c == '}') {
            if (st.top() == '{') st.pop();
            else return false;
        }
        else st.push(c);
    }

    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (check(s)) cout << "YES\n";
        else cout << "NO\n";
    }
}