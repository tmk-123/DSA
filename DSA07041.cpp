#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        stack<char> st;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push('(');
            }
            else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    cnt += 2;
                }  
            }
        }
        cout << cnt << endl;
    }
}