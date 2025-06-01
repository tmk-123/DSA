#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);
        return min({n - left, right + 1, left + 1 + n - right});
    }
};