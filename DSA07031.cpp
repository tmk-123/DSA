#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        stack<long long> st;
        
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            string s = v[i];

            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();

                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else st.push(a / b);
            }
            else st.push(stoll(s));
        }
        cout << st.top() << endl;
    }
}