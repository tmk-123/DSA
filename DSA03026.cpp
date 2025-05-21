#include<bits/stdc++.h>

using namespace std;

void findMin(int n, int s) {
    if (s < 1 || n*9 < s) {
        cout << -1 << " " << -1 << endl;
        return;
    }

    int s1 = s;
    vector<int> v1(n, 0);
    v1[0] = 1;
    s1--;
    for (int i = n - 1; i >= 0; i--) {
        if (s1 >= 9 - v1[i]) {
            s1 -= 9 - v1[i];
            v1[i] = 9;
        }
        else {
            v1[i] += s1;
            break;
        }
    }

    vector<int> v(n, 0);
    v[0] = 1;
    s--;
    for (int i = 0; i < n; i++) {
        if (s >= 9 - v[i]) {
            s -= 9 - v[i];
            v[i] = 9;
        }
        else {
            v[i] += s;
            break;
        }
    }

    for (int x : v1) cout << x;
    cout << " ";
    for (int x : v) cout << x;
    cout << endl;
}

int main() {
    int n, s;
    cin >> n >> s;
    findMin(n, s);
}