#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<string> st;
        string res;
        for (char c : s) {
            if (isalpha(c)) {
                st.push(string(1, c));
            }
            else {
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                st.push(c + b + a);
            }
        }
        cout << st.top() << endl;
    }
}