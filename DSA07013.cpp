#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<int> st;

        for (char c : s) {
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                if (c == '+')  st.push(a + b);
                else if (c == '-') st.push(b - a);
                else if (c == '*') st.push(a * b);
                else st.push(b / a);
            }
            else st.push(c - '0');

        }

        cout << st.top() << endl;
    }
}