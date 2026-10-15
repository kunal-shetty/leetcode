// 2913. Subarrays Distinct Element Sum of Squares I
// Difficulty: Easy
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
// Runtime: 42 ms (beats —)
// Memory: 36.3 MB (beats —)
// Submitted: 2026-10-15

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> set;
            for (int j = i; j < n; j++) {
                set.insert(nums[j]);
                res += set.size() * set.size();
            }
        }
        return res;
    }
};
