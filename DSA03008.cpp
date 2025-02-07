#include<bits/stdc++.h>

using namespace std;

struct Time {
    int start, end;
};

// chỉ cần sắp xếp theo thời gian kết thúc
bool compare(Time a, Time b) {
    return a.end < b.end;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<Time> time(n);
        for (int i = 0; i < n; i++) cin >> time[i].start;
        for (int i = 0; i < n; i++) cin >> time[i].end;

        sort(time.begin(), time.end(), compare);
        
        int cnt = 1;
        int lastEnd = time[0].end;
        for (int i = 1; i < n; i++) {
            if (lastEnd <= time[i].start) {
                cnt++;
                lastEnd = time[i].end;
            }
        }

        cout << cnt << endl;
    }
}