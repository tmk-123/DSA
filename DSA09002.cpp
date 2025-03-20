#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        int j;
        while (ss >> j) {
            if (i < j) {
                cout << i << " " << j << endl;
            }
        }
    } 
}