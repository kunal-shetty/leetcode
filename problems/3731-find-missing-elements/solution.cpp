// 3731. Find Missing Elements
// Difficulty: Easy
// https://leetcode.com/problems/find-missing-elements/
// Runtime: 0 ms (beats —)
// Memory: 33.8 MB (beats —)
// Submitted: 2026-08-04

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int small = INT_MAX, large = INT_MIN;
        vector<int> res;

        for (auto num : nums) {
            small = min(small, num);
            large = max(large, num);
        }

        unordered_set<int> set(nums.begin(), nums.end());

        for (int i = small; i <= large; i++) {
            if (set.find(i) == set.end()) {
                res.push_back(i);
            }
        }

        return res;
    }
};
