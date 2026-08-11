// 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
// Difficulty: Easy
// https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
// Runtime: 7 ms (beats —)
// Memory: 23 MB (beats —)
// Submitted: 2026-08-11

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int sum = nums[0];

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] == nums[i] + 1)
                sum += nums[i + 1];
            else
                break;
        }

        for (int x = sum; ; x++) {
            if (!set.contains(x))
                return x;
        }

        return -1; 
    }
};
