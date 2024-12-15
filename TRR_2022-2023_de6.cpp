#include<iostream>

using namespace std;

int n, k;
void Try(int cntB, string s, bool check) {
    if (s.length() == n) {
        if (check) cout << s << endl;
        return;
    }

    s.push_back('A');
    Try(0, s, check); // nếu push A thì cntB về 0
    s.pop_back();

    if (cntB < k - 1) {
        s.push_back('B');
        Try(cntB + 1, s, check);
        s.pop_back();
    }
    else if (cntB == k - 1 && !check) {
        s.push_back('B');
        Try(cntB + 1, s, true);
        s.pop_back();
    }
}
int main() {
    cin >> n >> k;

    Try(0, "", false);
}