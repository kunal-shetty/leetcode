// 3942. Minimum Operations to Sort a Permutation
// Difficulty: Medium
// https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/
// Runtime: 1 ms (beats —)
// Memory: 141.3 MB (beats —)
// Submitted: 2026-05-27

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), pos = find(nums.begin(), nums.end(), 0) - nums.begin(), ans = 1e9;

        bool increasing = true, decreasing = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) increasing = false;

            if ((nums[(i + 1) % n] - nums[i] + n) % n != n - 1)
                decreasing = false;
        }

        if (increasing) ans = min(pos, n - pos + 2);

        if (decreasing) {
            int k = n - 1 - pos;
            ans = min(ans, min(k + 1, n - k + 1));
        }

        return ans == 1e9 ? -1 : ans;
    }
};
