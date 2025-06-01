#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = capacity[i] - rocks[i];
        }

        sort(v.begin(), v.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) cnt++;
            else {
                if (additionalRocks >= v[i]) {
                    cnt++;
                    additionalRocks -= v[i];
                }
                else return cnt;
            }
        }
        return cnt;
    }
};