#include<bits/stdc++.h>

using namespace std;

long long priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

vector<string> infixToPostfix(string s) {
    stack<char> st;
    vector<string> v; 
    string num = "";

    for (char c : s) {
        if (isdigit(c)) {
            num += c;
        }   
        else {
            if (!num.empty()) {
                v.emplace_back(num);
                num = "";
            }

            if (c == '(') st.push(c);
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    v.emplace_back(string(1, st.top()));
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && priority(st.top()) >= priority(c)) {
                    v.emplace_back(string(1, st.top()));
                    st.pop();
                }
                st.push(c);   
            }
        }
    }

    if (!num.empty()) v.emplace_back(num);
    while (!st.empty()) {
        v.emplace_back(string(1, st.top()));
        st.pop();
    }
    return v;
}

long long calc(vector<string>& v) {
    stack<long long> st;
    for (auto& s : v) {
        if (isdigit(s[0])) st.push(stoll(s));
        else {  
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            
            if (s == "+") st.push(a + b);
            else if (s == "-") st.push(a - b);
            else if (s == "*") st.push(a * b);
            else st.push(a / b);
        }
    }

    return st.top();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<string> postfix = infixToPostfix(s);
        cout << calc(postfix) << endl;  
    }
}