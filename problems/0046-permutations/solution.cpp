// 46. Permutations
// Difficulty: Medium
// https://leetcode.com/problems/permutations/
// Runtime: 0 ms (beats —)
// Memory: 11 MB (beats —)
// Submitted: 2026-02-01

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);   
            backtrack(nums, index + 1);     
            swap(nums[index], nums[i]);     
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};
