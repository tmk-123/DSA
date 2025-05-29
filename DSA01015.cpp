#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
    int t;
    cin >> t;
    while (t--) {        
        cin >> n;
        queue<long long> q;
        q.push(9);

        while (1) {
            long long u = q.front(); q.pop();
            if (u % n == 0) {
                cout << u << endl;
                break;
            }

            q.push(u * 10);
            q.push(u * 10 + 9);
        }
    }
}