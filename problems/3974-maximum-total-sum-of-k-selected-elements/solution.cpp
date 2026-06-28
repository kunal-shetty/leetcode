// 3974. Maximum Total Sum of K Selected Elements
// Difficulty: Medium
// https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
// Runtime: 69 ms (beats —)
// Memory: 186.3 MB (beats —)
// Submitted: 2026-06-28

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long ans = 0;;

        for(int i = 0; i < k; i++){
            ans += nums[i];
        }
        int L = min(k, mul - 1);

        for(int i = 0; i < L; i++){
            ans += 1LL * nums[i] * (mul - i - 1);
        }
        return ans;
    }
};
