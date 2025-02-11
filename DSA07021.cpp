#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    stack<int> st;
    st.push(-1); // vị trí biên để tính khoảng cách
    int maxLength = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i); 
        } else {
            st.pop(); 
            if (!st.empty()) {
                maxLength = max(maxLength, i - st.top());
            } else {
                st.push(i); // Lưu vị trí ')' không hợp lệ để xác định biên tiếp theo, giống -1 ban đầu
            }
        }
    }
    return maxLength;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
