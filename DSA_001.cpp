#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) 
        if (n % i == 0) return false;
    return true;
}
int main() {
    int l, r;
    cin >> l >> r;

    queue<int> q;
    q.push(2); q.push(3); q.push(5); q.push(7);
    int count = 0;
    vector<int> v = {1, 3, 5, 7, 9};

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (l <= num && r >= num) count++;
        for (int x : v) {
            long newNum = num * 10 + x;
            if (newNum > r) break;

            if (isPrime(newNum)) {
                q.push(newNum);
            }
        }
    }

    cout << count << endl;
}