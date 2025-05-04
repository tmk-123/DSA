#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        stack<int> st;
        a.push_back(0); // push 0 để xử lý hết nếu không có while
        long long maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && a[st.top()] > a[i]) {
                int height = a[st.top()]; st.pop();
                
                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                
                maxArea = max(maxArea, 1LL * height * width);    
            }
            st.push(i);
        }

        cout << maxArea << endl;
    }
}