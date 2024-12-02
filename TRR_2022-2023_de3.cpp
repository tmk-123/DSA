#include<iostream>
#include<vector>

using namespace std;

vector<int> res;
void Try (int n, int k, int a[], int index, int sum) {
    if (k == 0) {
        if (sum == 0) {
            for (int x : res) {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = index; i <= n; i++) {
        res.push_back(a[i]);
        Try(n, k - 1, a, i + 1, sum - a[i]);
        res.pop_back();
    }

    return;
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int N;
    cin >> N;
    Try(n, k, a, 0, N);
    return 0;
}