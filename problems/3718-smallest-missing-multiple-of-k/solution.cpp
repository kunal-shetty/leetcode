// 3718. Smallest Missing Multiple of K
// Difficulty: Easy
// https://leetcode.com/problems/smallest-missing-multiple-of-k/
// Runtime: 0 ms (beats —)
// Memory: 25.1 MB (beats —)
// Submitted: 2026-08-25

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int res = k;
        while (seen.count(res)) {
            res += k;
        }
        return res;
    }
};
