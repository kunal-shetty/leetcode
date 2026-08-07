// 2779. Maximum Beauty of an Array After Applying Operation
// Difficulty: Medium
// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
// Runtime: 48 ms (beats —)
// Memory: 105 MB (beats —)
// Submitted: 2026-08-07

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] - nums[start] > 2 * k)
                start++;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
