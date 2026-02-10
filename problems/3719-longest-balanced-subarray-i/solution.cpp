// 3719. Longest Balanced Subarray I
// Difficulty: Medium
// https://leetcode.com/problems/longest-balanced-subarray-i/
// Runtime: 1889 ms (beats —)
// Memory: 530.3 MB (beats —)
// Submitted: 2026-02-10

class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> odd;
            unordered_set<int> even;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2) {
                    odd.insert(nums[j]);
                } else {
                    even.insert(nums[j]);
                }
                if (odd.size() == even.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
