#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v;

int check;

void Try(int cnt, int sum, int target) {
    if (check) return;
    if (cnt == k) {
        check = 1;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (sum == target) Try(cnt + 1, 0, target);
        else {
            if (sum > target) return;
            Try(cnt, sum + v[i], target); 
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        v.resize(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }

        if (sum % k != 0) cout << 0 << endl;
        else {
            int target = sum / k;
            check = 0;
            Try(0, 0, target);
            cout << check << endl;
        }
    }
}