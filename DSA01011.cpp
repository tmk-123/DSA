#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int test;
        string s;
        cin >> test >> s;
        
        int n = s.size();
        char idx = n;
        while (idx > 0 && s[idx - 1] >= s[idx]) {
            idx--;
        }

        if (idx == 0) {
            cout << test << " BIGGEST" << endl;
        }
        else {
            idx--;
            int k = idx;
            for (int i = idx + 1; i < n; i++) {
                if (s[i] > s[idx]) {
                    k = i;
                }
            }

            swap(s[idx], s[k]);
            int left = idx + 1, right = n - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }

            cout << test << " ";
            for (int i = 0; i < n; i++) {
                cout << s[i]; 
            }
            cout << endl;
        }
    }
}