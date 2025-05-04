#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<bool> st; // lưu trạng thái đổi dấu không
        st.push(false); // ban đầu chưa đổi dấu
        string res;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                if (i > 0 && s[i - 1] == '-') st.push(!st.top());
                else st.push(st.top());
            }
            else if (c == ')') st.pop();
            else if (c == '+' || c == '-') {
                if (st.top()) {
                    if (c == '+') res += '-';
                    else res += '+';
                }
                else res += c;
            }
            else res += c;
        }
        
        cout << res << endl;
    }
}