#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nextGreater(n, -1), v(n);
        stack<int> st;
        for (int i = 0; i < n; i++) cin >> v[i];  
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] <= v[i]) {
                st.pop();
            }
            if (!st.empty()) nextGreater[i] = st.top();
            st.push(i);
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int idx = nextGreater[i];
            if (idx == -1) continue;
            for (int j = idx + 1; j < n; j++) {
                if (v[j] < v[idx]) {
                    ans[i] = v[j];
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}