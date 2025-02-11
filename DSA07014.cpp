#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<int> st;

        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                if (c == '+')  st.push(a + b);
                else if (c == '-') st.push(a - b);
                else if (c == '*') st.push(a * b);
                else st.push(a / b);
            }
            else st.push(c - '0');

        }

        cout << st.top() << endl;
    }
}