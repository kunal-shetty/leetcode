// 2333. Minimum Sum of Squared Difference
// Difficulty: Medium
// https://leetcode.com/problems/minimum-sum-of-squared-difference/
// Runtime: 7 ms (beats —)
// Memory: 136.3 MB (beats —)
// Submitted: 2026-10-10

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> freq(100001);
        long long ops = k1 + k2, totalDiff = 0, res = 0;
        int maxDiff = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int diff = abs(nums1[i] - nums2[i]);
            freq[diff]++;
            totalDiff += diff;
            maxDiff = max(maxDiff, diff);
        }

        if (totalDiff <= ops) return 0;

        for (int i = maxDiff; i > 0 && ops > 0; i--) {
            int r = min(ops, (long long)freq[i]);
            freq[i] -= r;
            freq[i - 1] += r;
            ops -= r;
        }

        for (int i = 1; i <= maxDiff; i++)
            res += 1LL * i * i * freq[i];

        return res;
    }
};
