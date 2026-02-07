// 3634. Minimum Removals to Balance Array
// Difficulty: Medium
// https://leetcode.com/problems/minimum-removals-to-balance-array/
// Runtime: 39 ms (beats —)
// Memory: 104.9 MB (beats —)
// Submitted: 2026-02-07

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, maxsize = 0;

        for (int r = 0; r < n; ++r) {
            while (l <= r && (long long)nums[r] > (long long)nums[l] * k)
                ++l;
            if (r - l + 1 > maxsize)
                maxsize = r - l + 1;
        }
        return n - maxsize;
    }
};
