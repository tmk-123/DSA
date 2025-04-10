#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        stack<long long> st;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();

                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(b - a);
                else if (s == "*") st.push(a * b);
                else st.push(b / a);
            }
            else st.push(stoll(s));
        }
        cout << st.top() << endl;
    }
}