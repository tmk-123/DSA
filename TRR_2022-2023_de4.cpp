#include<iostream>
#include<vector>

using namespace std;

vector<int> res;
int a[100];

void Try(int n, int k, int index) {
    if (k == 0) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = index; i < n; i++) {
        res.push_back(a[i]);
        Try(n, k - 1, i + 1);
        res.pop_back();
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Try(n, k, 0);
    return 0;
}