// 4010. Maximize Pair Strength Using GCD
// Difficulty: Easy
// https://leetcode.com/problems/maximize-pair-strength-using-gcd/
// Runtime: 770 ms (beats —)
// Memory: 37.3 MB (beats —)
// Submitted: 2026-08-02

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxStrength = LLONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long g = gcd(nums[i], nums[j]);
                long long s = (1LL * nums[i] * nums[j]) / (g * g);
                maxStrength = max(maxStrength, s);
            }
        }
        return maxStrength;
    }
};
