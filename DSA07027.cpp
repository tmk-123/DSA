#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        stack<int> st;
        st.push(a[n - 1]);
        vector<int> res;
        res.push_back(-1);
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < st.top()) res.push_back(st.top());
            else {
                while (!st.empty() && a[i] >= st.top()) {
                    st.pop();
                }

                if (!st.empty()) res.push_back(st.top());
                else res.push_back(-1);
            }

            st.push(a[i]);
        }


        for (int i = res.size() - 1; i >= 0; i--) {
            cout << res[i] << " "; 
        }
        cout << endl;
    }
}