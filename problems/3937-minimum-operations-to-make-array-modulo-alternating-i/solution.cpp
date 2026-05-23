// 3937. Minimum Operations to Make Array Modulo Alternating I
// Difficulty: Medium
// https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/
// Runtime: 0 ms (beats —)
// Memory: 24.9 MB (beats —)
// Submitted: 2026-05-23

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> even(k, 0), odd(k, 0);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                int current = nums[j] % k;
                int diff = abs(current - i);
                diff = min(diff, k - diff);

                if (j % 2 == 0)
                    even[i] += diff;
                else
                    odd[i] += diff;
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i != j)
                    ans = min(ans, even[i] + odd[j]);
            }
        }

        return ans;
    }
};
