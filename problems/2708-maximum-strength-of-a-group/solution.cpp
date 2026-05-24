// 2708. Maximum Strength of a Group
// Difficulty: Medium
// https://leetcode.com/problems/maximum-strength-of-a-group/
// Runtime: 0 ms (beats —)
// Memory: 51.8 MB (beats —)
// Submitted: 2026-05-24

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int negativeCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                negativeCount++;
            else
                break;
        }

        negativeCount =
            (negativeCount % 2 == 0) ? negativeCount : negativeCount - 1;

        long long res = 1;
        bool taken = false;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] < 0 && negativeCount == 0)
                continue;

            if (nums[i] != 0) {
                res *= nums[i];
                taken = true;
            }

            if (nums[i] < 0 && negativeCount > 0)
                negativeCount--;
        }

        if (!taken) {
            int mx = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                mx = max(mx, nums[i]);
            }

            return mx;
        }
        return res;
    }
};
