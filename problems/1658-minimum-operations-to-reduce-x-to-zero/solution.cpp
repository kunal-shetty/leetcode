// 1658. Minimum Operations to Reduce X to Zero
// Difficulty: Medium
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Runtime: 3 ms (beats —)
// Memory: 102.3 MB (beats —)
// Submitted: 2026-09-23

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), total = 0;
        for (auto num : nums)
            total += num;

        int target = total - x;
        if (target < 0)
            return -1;
        if (target == 0)
            return n;

        int left = 0, sum = 0, len = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > target)
                sum -= nums[left++];
            if (sum == target)
                len = max(len, right - left + 1);
        }

        return len == -1 ? -1 : n - len;
    }
};
