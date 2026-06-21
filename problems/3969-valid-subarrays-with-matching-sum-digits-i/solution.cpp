// 3969. Valid Subarrays With Matching Sum Digits I
// Difficulty: Medium
// https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/
// Runtime: 155 ms (beats —)
// Memory: 34.5 MB (beats —)
// Submitted: 2026-06-21

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long sum = pref[j + 1] - pref[i];
                if (sum % 10 != x)
                    continue;

                long long f = sum;
                while (f >= 10)
                    f /= 10;
                if (f == x)
                    ans++;
            }
        }
        return ans;
    }
};
