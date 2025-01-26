#include<bits/stdc++.h>

using namespace std;

vector<string> res;
void Try(int n, string s) {
    if (n == s.length()) {
        res.push_back(s);
        return;
    }

    Try(n, s + '0');
    Try(n, s + '1');
}

bool check(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    Try(n, "");
    for (string s : res) {
        if (check(s)) {
            for (char c : s) {
                cout << c << " ";
            }
            cout << endl;
        }
    }
}