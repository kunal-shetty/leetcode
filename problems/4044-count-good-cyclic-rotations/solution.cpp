// 4044. Count Good Cyclic Rotations
// Difficulty: Medium
// https://leetcode.com/problems/count-good-cyclic-rotations/
// Runtime: 16 ms (beats —)
// Memory: 116.2 MB (beats —)
// Submitted: 2026-09-06

class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size(), m = n / 2, res = 0;
        long long t = 0, win = 0;
        vector<int> a(nums);
        a.insert(a.end(), nums.begin(), nums.end());

        for (auto num : nums)
            t += num;
        for (int i = 0; i < m; i++) {
            win += a[i];
        }
        for (int i = 0; i < n; i++) {
            res += 2 * win > t;
            win += a[i + m] - a[i];
        }
        return res;
    }
};
