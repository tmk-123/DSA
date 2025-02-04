#include<bits/stdc++.h>

using namespace std;

void Try(vector<int> v) {
    vector<int> temp;
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        if (i > 0) {
            temp.push_back(v[i] + v[i - 1]);
            cout << " ";
        }
        cout << v[i];
    }
    cout << "]" << endl;

    if (!temp.empty()) Try(temp);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        Try(v);
    }
}