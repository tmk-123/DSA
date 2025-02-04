#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    unordered_set<int> Set;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        Set.insert(a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (Set.find(a[i]) != Set.end()) {
            cout << a[i] << " ";
            Set.erase(a[i]);
        }
    } 
}