#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<string> st;
        string num;

        for (int i = 0; i < s.length(); i++) {
            if ('0' <= s[i] && s[i] <= '9') num += s[i];
            else if (s[i] == '[') {
                st.push(num);
                st.push("[");
                num = "";
            }
            else if (s[i] == ']') {
                string a;
                while (!st.empty() && st.top() != "[") {
                    a = st.top() + a;
                    st.pop();
                }
                st.pop();
                
                int n = 1;
                if (st.top().size()) n = stoi(st.top()); // có thể n = 1 nta ẩn đi !?
                st.pop();

                string b;
                while (n--) b += a;
                st.push(b);
            }
            else st.push(string(1, s[i]));
        }

        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        cout << res << endl;
    }
} 