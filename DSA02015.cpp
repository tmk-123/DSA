#include<bits/stdc++.h>

using namespace std;

string s;
set<string> res;

// balance : theo dõi ngoặc đóng, mở, cân bằng khi balance = 0
void Try(int i, int left, int right, int balance, string curr) {
    if (i == s.size()) {
        if (left == 0 && right == 0 && balance == 0 && curr.size() > 1) {
            res.insert(curr);
        }
        return;
    }

    char c = s[i];
    if (c == '(') {
        if (left > 0) Try(i + 1, left - 1, right, balance, curr);
        Try(i + 1, left, right, balance + 1, curr + c);
    }  
    else if (c == ')') {
        if (right > 0) Try(i + 1, left, right - 1, balance, curr);

        // nếu đã mở ngoặc trước đó, hay balance > 0
        if (balance > 0) Try(i + 1, left, right, balance - 1, curr + c);
    }
    else Try(i + 1, left, right, balance, curr + c);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        int left = 0, right = 0; // số '(' và ')' cần xóa
        for (char c : s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++; // không xóa được '(' nữa
            }
        }

        res.clear();
        Try(0, left, right, 0, "");

        if (res.empty()) cout << -1 << endl;
        else {
            for (auto& x : res) cout << x << " ";
            cout << endl;
        }
    }
}