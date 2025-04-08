#include <bits/stdc++.h>
using namespace std;

bool isValidInorder(vector<int>& A) {
    for (int i = 0; i < A.size() - 1; ++i) {
        if (A[i] >= A[i + 1]) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        cout << (isValidInorder(A) ? 1 : 0) << endl;
    }
    return 0;
}
