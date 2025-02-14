#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s; 
        set<char> Set;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (char c : s) {
                Set.insert(c);
            }
        }

        for (char c : Set) {
            cout << c << " ";
        }
        cout << endl;
    }
}