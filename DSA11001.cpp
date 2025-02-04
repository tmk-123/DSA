#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++) {
            if ('a' <= s[i] && s[i] <= 'z') st.push(string(1, s[i]));
            else {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();

                st.push(b + s[i] + a);
            }
        }

        cout << st.top() << endl;
    }
}