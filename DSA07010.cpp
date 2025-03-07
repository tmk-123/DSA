#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<string> st;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();

                string temp = a + b + s[i];
                st.push(temp);
            }
            else st.push(string(1, s[i]));
        }

        cout << st.top() << endl;
    }
} 