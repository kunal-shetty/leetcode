// 3640. Trionic Array II
// Difficulty: Hard
// https://leetcode.com/problems/trionic-array-ii/
// Runtime: 0 ms (beats —)
// Memory: 132.5 MB (beats —)
// Submitted: 2026-02-04

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        long long a = LLONG_MIN, b = LLONG_MIN, c = LLONG_MIN;
        long long ans = LLONG_MIN;

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] < nums[i + 1]) {
                if (b != LLONG_MIN || c != LLONG_MIN) {
                    c = 1LL * nums[i + 1] + max(b, c);
                    ans = max(ans, c);
                }
                a = max(1LL * nums[i], a) + 1LL * nums[i + 1];
                b = LLONG_MIN;
            }

            else if (nums[i] > nums[i + 1]) {
                if (a != LLONG_MIN || b != LLONG_MIN)
                    b = 1LL * nums[i + 1] + max(a, b);
                a = c = LLONG_MIN;
            }

            else
                a = b = c = LLONG_MIN;
        }
        if (ans == LLONG_MIN)
            return 0;
        return ans;
    }
};
