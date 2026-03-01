// 228. Summary Ranges
// Difficulty: Easy
// https://leetcode.com/problems/summary-ranges/
// Runtime: 0 ms (beats —)
// Memory: 9.3 MB (beats —)
// Submitted: 2026-03-01

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int start = nums[i];

            while (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
                i++;
            }

            if (start == nums[i]) {

                res.push_back(to_string(start));
            } else {
                res.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }

        return res;
    }
};
