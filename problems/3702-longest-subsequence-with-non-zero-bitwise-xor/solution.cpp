// 3702. Longest Subsequence With Non-Zero Bitwise XOR
// Difficulty: Medium
// https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
// Runtime: 0 ms (beats —)
// Memory: 179.3 MB (beats —)
// Submitted: 2026-09-10

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int> zeros(n, 0);
        if (nums == zeros) 
            return 0;

        int a = 0;
        for (auto num : nums) {
            a ^= num;
        }

        return a ? n : n - 1;
    }
};
