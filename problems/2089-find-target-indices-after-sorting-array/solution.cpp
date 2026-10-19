// 2089. Find Target Indices After Sorting Array
// Difficulty: Easy
// https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Runtime: 0 ms (beats 100.0%)
// Memory: 15.1 MB (beats 52.0%)
// Submitted: 2026-10-19

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) res.push_back(i);
        }
        return res;
    }
};
