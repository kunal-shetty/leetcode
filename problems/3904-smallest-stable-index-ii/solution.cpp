// 3904. Smallest Stable Index II
// Difficulty: Medium
// https://leetcode.com/problems/smallest-stable-index-ii/
// Runtime: 15 ms (beats —)
// Memory: 210.9 MB (beats —)
// Submitted: 2026-09-05

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefMax(n), suffixMin(n);
        prefMax[0] = nums[0];
        suffixMin[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(prefMax[i] - suffixMin[i] <= k) return i;
        }
        return -1;
    }
};
