// 4031. Find All Numbers Disappeared in an Array II
// Difficulty: Medium
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/
// Runtime: 51 ms (beats —)
// Memory: 242.6 MB (beats —)
// Submitted: 2026-08-23

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        vector<bool> seen(upper - lower + 1, false);
        for (auto num : nums) {
            if (num >= lower && num <= upper)
                seen[num - lower] = true;
        }

        vector<vector<int>> ans;
        for (int i = 0; i < seen.size(); i++) {
            if (seen[i])
                continue;

            int start = i;
            while (i + 1 < seen.size() && !seen[i + 1])
                i++;

            ans.push_back({lower + start, lower + i});
        }
        return ans;
    }
};
