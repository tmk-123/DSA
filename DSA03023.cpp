#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    int x = 0, t = 0, d = 0;
    for (char c : s) {
        if (c == 'X') x++;
        else if (c == 'T') t++;
        else if (c == 'D') d++;
    }

    // ban đầu đếm số khác X ở vùng X, và khác D ở vùng D
    // cnt lúc ấy là số lỗi sai ở vùng D, X. nếu D, X đúng thì T cũng đúng theo
    // sau đó nếu có thể đỗi chổ trục tiếp thì 2 lỗi sai = 1 swap, còn 1 lỗi với phần T là 1 swap
    int cnt = 0;
    for (int i = 0; i < x; i++) {
        if (s[i] != 'X') cnt++;
    }
    for (int i = n - d; i < n; i++) {
        if (s[i] != 'D') cnt++;
    }
    
    int a = 0, b = 0;
    for (int i = 0; i < x; i++) {
        if (s[i] == 'D') a++;
    }
    for (int i = n - d; i < n; i++) {
        if (s[i] == 'X') b++;
    }

    // min(a, b) là số phép có thể swap giữa D, X
    cout << cnt - min(a, b);
}