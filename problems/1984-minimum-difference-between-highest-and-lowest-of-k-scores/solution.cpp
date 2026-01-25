// 1984. Minimum Difference Between Highest and Lowest of K Scores
// Difficulty: Easy
// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Runtime: 3 ms (beats —)
// Memory: 17.3 MB (beats —)
// Submitted: 2026-01-25

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[k - 1] - nums[0];
        for(int i = 0; i + k <= n; i ++){
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};
