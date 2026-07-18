// 78. Subsets
// Difficulty: Medium
// https://leetcode.com/problems/subsets/
// Runtime: 0 ms (beats —)
// Memory: 10.1 MB (beats —)
// Submitted: 2026-07-18

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        solve(idx + 1, nums);

        subset.pop_back();
        solve(idx + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};
