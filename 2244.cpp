#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for (int t : tasks) {
            m[t]++;
        }      

        int cnt = 0;
        for (auto [task, freq] : m) {
            if (freq == 1) return -1;
            cnt += ceil(freq / 3.0);
        }
        return cnt;
    }
};