#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        vector<int> v(1000001, -1);
        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            if (v[cards[i]] != -1) {
                ans = min(ans, i - v[cards[i]] + 1);
            }
            v[cards[i]] = i;
        }      
        if (ans == INT_MAX) return -1;
        return ans;
    }
};