#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    stack<int> st;
    
    while (t--) {
        string s;
        getline(cin >> ws, s);
        if (s == "POP") {
            if (!st.empty()) st.pop();
        }
        else if (s == "PRINT") {
            if (!st.empty()) {
                cout << st.top() << endl;
            }
            else cout << "NONE\n";
        }
        else {
            string t = s.substr(s.find(" "));
            st.push(stoi(t));
        }
    }
}