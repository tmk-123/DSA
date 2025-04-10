#include <bits/stdc++.h>
using namespace std;

// Hàm trả về độ ưu tiên của toán tử
int priority(char op) {
    if (op == '%' || op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        stack<char> st;
        string res;

        for (char c : s) {
            if (isalpha(c)) {
                res += c; // nếu là toán hạng thì đưa vào kết quả
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // bỏ dấu '('
            }
            else { // là toán tử
                while (!st.empty() && priority(st.top()) >= priority(c)) {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        cout << res << endl;
    }
}
