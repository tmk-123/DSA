#include<bits/stdc++.h>

using namespace std;

bool check(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == ')') {
            bool hasOperator = false;
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/') hasOperator = true; 
            }
            if (st.empty() || !hasOperator) return true;
            if (!st.empty()) st.pop(); // xóa dấu ( 
        }
        else st.push(c);
    }

    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (check(s)) cout << "Yes\n";
        else cout << "No\n";
    }
}