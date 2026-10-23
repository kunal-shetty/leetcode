// 4083. Minimum Deletions to Make Array Sharp
// Difficulty: Easy
// https://leetcode.com/problems/minimum-deletions-to-make-array-sharp/
// Runtime: 0 ms (beats 100.0%)
// Memory: 31.1 MB (beats 27.1%)
// Submitted: 2026-10-23

class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int del = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] == nums[i]) del++;
        }
        return del;
    }
};
