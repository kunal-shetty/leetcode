// 4430. minimum deletions to make array sharp
// Difficulty: Unknown
// https://leetcode.com/problems/minimum-deletions-to-make-array-sharp/
// Runtime: 3 ms (beats 0.0%)
// Memory: 31.3 MB (beats 66.7%)
// Submitted: 2026-10-18

class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i =0; i < n-1; i++){
            if(nums[i] == nums[i + 1]) res++;
        }
        return res;
    }
};
