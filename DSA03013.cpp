#include <bits/stdc++.h>
using namespace std;

void solve() {
    int D;
    string S;
    cin >> D >> S;
    
    vector<int> freq(256, 0); 
    for (char c : S) {
        freq[c]++;
    }

    int maxFreq = *max_element(freq.begin(), freq.end()); 

    if ((maxFreq - 1) * D + 1 <= S.size()) {
        cout << "1\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
