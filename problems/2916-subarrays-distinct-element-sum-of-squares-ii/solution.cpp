// 2916. Subarrays Distinct Element Sum of Squares II
// Difficulty: Hard
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/
// Runtime: 83 ms (beats 100.0%)
// Memory: 101.7 MB (beats 88.3%)
// Submitted: 2026-10-16

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> countBIT(n + 1, 0), sumBIT(n + 1, 0);
        unordered_map<int, int> last;
        long long res = 0;

        for (int right = 0; right < n; right++) {
            int prev = last.count(nums[right]) ? last[nums[right]] : -1;

            long long count = 0, sum = 0;
            for (int i = n - prev - 1; i > 0; i -= i & -i)
                count += countBIT[i], sum += sumBIT[i];

            long long diff = right - prev;
            long long d = diff * diff - 2 * (sum - prev * count);
            res = (res + (n - right) * d) % MOD;

            for (int i = n - prev; i <= n; i += i & -i)
                countBIT[i]++, sumBIT[i] += prev;

            last[nums[right]] = right;
        }
        return res;
    }
};
