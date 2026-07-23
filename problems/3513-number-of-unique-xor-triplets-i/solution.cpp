// 3513. Number of Unique XOR Triplets I
// Difficulty: Medium
// https://leetcode.com/problems/number-of-unique-xor-triplets-i/
// Runtime: 0 ms (beats —)
// Memory: 198.9 MB (beats —)
// Submitted: 2026-07-23

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int ans = 1;
        while (ans <= n) {
            ans <<= 1;
        }
        return ans;
    }
};
