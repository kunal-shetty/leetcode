// 2897. Apply Operations on Array to Maximize Sum of Squares
// Difficulty: Hard
// https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/
// Runtime: 67 ms (beats —)
// Memory: 90.6 MB (beats —)
// Submitted: 2026-10-12

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(30);
        long long res = 0, MOD = 1e9 + 7;

        for (int num : nums) {
            for (int i = 0; i < 30; i++) {
                if (num & (1 << i)) bits[i]++;
            }
        }

        while (k--) {
            long long x = 0;

            for (int i = 0; i < 30; i++) {
                if (bits[i] > 0) {
                    x |= 1 << i;
                    bits[i]--;
                }
            }
            
            res = (res + x * x) % MOD;
        }

        return res;
    }
};
