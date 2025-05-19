#include<bits/stdc++.h>

using namespace std;

struct Job {
    int a, b, c;
};

bool compare(Job x, Job y) {
    return x.c > y.c;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Job> v;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back({a, b, c});
        }

        sort(v.begin(), v.end(), compare);
        
        int maxDeadline = 0;
        for (auto j : v) {
            maxDeadline = max(maxDeadline, j.b);
        }

        vector<bool> visited(maxDeadline + 1, false);
        int count = 0, profit = 0;

        for (int i = 0; i < n; i++) {
            // còn cái nào chưa lấy thì lấy từ trên xuống(tham lam)
            for (int j = v[i].b; j >= 1; j--) {
                if (!visited[j]) {
                    visited[j] = true;
                    count++;
                    profit += v[i].c;
                    break;
                }
            }
        }

        cout << count << " " << profit << endl;
    }
}