#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
        long cost = 0;
        while (!pq.empty()) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            int sum = a + b;
            cost += sum;
            if (!pq.empty()) pq.push(sum);
        }

        cout << cost << endl;
    }
}