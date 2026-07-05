// 3984. Divisible Game
// Difficulty: Medium
// https://leetcode.com/problems/divisible-game/
// Runtime: 166 ms (beats —)
// Memory: 47.7 MB (beats —)
// Submitted: 2026-07-05

class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        int maxVal = INT_MIN;
        for (auto num : nums)
            maxVal = max(maxVal, num);

        vector<char> isDivisor(maxVal + 2, 0);
        for (auto num : nums) {
            for (int d = 2; d * d <= num; d++) {
                if (num % d == 0) {
                    isDivisor[d] = 1;
                    isDivisor[num / d] = 1;
                }
            }
            if (num > 1)
                isDivisor[num] = 1;
        }
        int k0 = -1;

        for (int k = 2; k <= maxVal + 1; k++) {
            if (!isDivisor[k]) {
                k0 = k;
                break;
            }
        }
        long long bestD = LLONG_MIN;
        int bestK = -1;

        for (int k = 2; k <= maxVal + 1; k++) {
            if (k != k0 && !isDivisor[k]) {
                continue;
            }

            long long curSum = 0, maxSum = LLONG_MIN;
            for (int i = 0; i < n; i++) {
                long long val = (nums[i] % k == 0) ? nums[i] : -nums[i];
                curSum = max(val, curSum + val);
                maxSum = max(maxSum, curSum);
            }
            if (maxSum > bestD) {
                bestD = maxSum;
                bestK = k;
            }
        }
        long long product = ((bestD % MOD) * (bestK % MOD)) % MOD;
        product = (product % MOD + MOD) % MOD;
        return product;
    }
};
