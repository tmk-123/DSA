#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int countNeg = 0, countZero = 0;
        int idx = -1, n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) countZero++;
            else if (nums[i] < 0) {
                countNeg++;
                idx = i;
            } 
        }

        if (n == 1) return nums[0];
        if (countZero == n) return 0;
        if (countNeg == 1 && countZero + countNeg == n) return 0;

        long long res = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            if (countNeg % 2 == 1 && i == idx) continue;
            res *= nums[i];
        }
        return res;
    }
};