#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    deque<int> dq;
    while (t--) {
        string s;
        cin >> s;
        if (s == "PUSHFRONT") {
            int n;
            cin >> n;
            dq.push_front(n);
        }
        else if (s == "PRINTFRONT") {
            if (!dq.empty()) cout << dq.front() << endl;
            else cout << "NONE" << endl;
        }
        else if (s == "POPFRONT") {
            if (!dq.empty()) dq.pop_front();
        }
        else if (s == "PUSHBACK") {
            int n;
            cin >> n;
            dq.push_back(n);
        }
        else if (s == "PRINTBACK") {
            if (!dq.empty()) cout << dq.back() << endl;
            else cout << "NONE" << endl;
        }
        else {
            if (!dq.empty()) dq.pop_back();
        }
    }
}