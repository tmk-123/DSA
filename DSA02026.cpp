#include<bits/stdc++.h>

using namespace std;

bool match(string s, int n) {
    string t = to_string(n);
    for (int i = 0; i < t.size(); i++) {
        if (s[i] != '?' && s[i] != t[i]) return false;
    }
    return true;
}

vector<int> generate(string s) {
    vector<int> res;
    for (int i = 10; i <= 99; i++) {
        if (match(s, i)) res.push_back(i);
    }
    return res;
}

vector<char> generate_op(string s) {
    vector<char> res;
    if (s == "?") return {'+', '-', '*', '/'};
    return {s[0]};
}

string solve() {
    string s;
    getline(cin >> ws, s);

    // a op b = c
    string a, op, b, c;
    a = s.substr(0, 2);
    op = s.substr(3, 1);
    b = s.substr(5, 2);
    c = s.substr(10, 2);

    // tập các trường hợp có thể
    vector<int> as = generate(a);
    vector<int> bs = generate(b);
    vector<char> ops = generate_op(op);

    for (int x : as) {
        for (char o : ops) {
            for (int y : bs) {
                int z = 0;
                bool valid = true;
                if (o == '+') z = x + y;
                else if (o == '-') z = x - y;
                else if (o == '*') z = x * y;
                else {
                    if (y == 0 || x % y != 0) continue;
                    z = x / y;
                }

                if (z < 10 || z > 99) continue;

                // nếu match được sẽ tự có số thỏa mãn để thay '?'
                if (match(c, z)) {
                    return to_string(x) + " " + string(1, o) + " " + to_string(y) + " = " + to_string(z);
                }
            }
        }
    }

    return "WRONG PROBLEM!";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}