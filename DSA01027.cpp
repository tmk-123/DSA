#include<bits/stdc++.h>

using namespace std;

vector<int> res;
void Try(int n, vector<bool>& visited, int a[]) {
    if (res.size() == n) {
        for (int x : res) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            res.push_back(a[i]);
            Try(n, visited, a);
            visited[i] = false;
            res.pop_back();
        }
    }
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<bool> visited(n, false);
    Try(n, visited, a);
}   