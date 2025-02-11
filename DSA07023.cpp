#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);

        stack<string> st;
        string token;
        while (ss >> token) {
            st.push(token);
        }

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}