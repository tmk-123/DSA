#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        stack<int> st;
        int cnt = 1;
        string res;
        for (int i = 0; i <= s.length(); i++) {
            st.push(cnt++);
            if (i == s.length() || s[i] == 'I') {
                while (!st.empty()) {
                    res += to_string(st.top());
                    st.pop(); 
                }
            }
        }

        cout << res << endl;
    }
}